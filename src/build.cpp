#include "build.h"

bool siren_build_install(mrb_state* mrb, struct RClass* rclass)
{
  rclass = mrb_define_module(mrb, "Build");
  mrb_define_class_method(mrb, rclass, "vertex",   siren_build_vertex,   ARGS_REQ(3));
  mrb_define_class_method(mrb, rclass, "line",     siren_build_line,     ARGS_REQ(2));
  mrb_define_class_method(mrb, rclass, "compound", siren_build_compound, ARGS_REQ(1));
  mrb_define_class_method(mrb, rclass, "polyline", siren_build_polyline, ARGS_REQ(1));
  return true;
}

mrb_value siren_build_vertex(mrb_state* mrb, mrb_value self)
{
  mrb_float x, y, z;
  int argc = mrb_get_args(mrb, "fff", &x, &y, &z);

  mrb_value res = mrb_class_new_instance(mrb, 0, NULL, mrb_class_get(mrb, "Shape"));
  TopoDS_Shape* shape = siren_shape_get(mrb, res);

  Standard_Real xx = (Standard_Real)x;
  Standard_Real yy = (Standard_Real)y;
  Standard_Real zz = (Standard_Real)z;

  *shape = BRepBuilderAPI_MakeVertex(gp_Pnt(xx, yy, zz));

  return res;
}

mrb_value siren_build_line(mrb_state* mrb, mrb_value self)
{
  mrb_value sp, tp;
  int argc = mrb_get_args(mrb, "oo", &sp, &tp);

  gp_Vec* s = siren_vec_get(mrb, sp);
  gp_Vec* t = siren_vec_get(mrb, tp);

  TopoDS_Shape* shape = new TopoDS_Shape();
  *shape = BRepBuilderAPI_MakeEdge(gp_Pnt(s->X(), s->Y(), s->Z()), gp_Pnt(t->X(), t->Y(), t->Z()));

  return siren_shape_new(mrb, shape);
}

mrb_value siren_build_polyline(mrb_state* mrb, mrb_value self)
{
  mrb_value ary;
  int argc = mrb_get_args(mrb, "A", &ary);

  BRepBuilderAPI_MakePolygon poly;

  for (int i = 0; i < mrb_ary_len(mrb, ary); i++) {
    mrb_value item = mrb_ary_ref(mrb, ary, i);
    gp_Vec* v = siren_vec_get(mrb, item);
    poly.Add(gp_Pnt(v->X(), v->Y(), v->Z()));
  }

  TopoDS_Shape* shape = new TopoDS_Shape();
  *shape = poly.Wire();

  return siren_shape_new(mrb, shape);
}

mrb_value siren_build_curve(mrb_state* mrb, mrb_value self)
{
  mrb_value pts, vecs;
  int argc = mrb_get_args(mrb, "A|A", &pts, &vecs);

  int psize = mrb_ary_len(mrb, pts);
  Handle(TColgp_HArray1OfPnt) pary = new TColgp_HArray1OfPnt(1, psize);
  for (int i=0; i<psize; i++) {
    mrb_value pt = mrb_ary_ref(mrb, pts, i);
    gp_Vec* pnt = siren_vec_get(mrb, pt);
    pary->SetValue(i+1, gp_Pnt(pnt->X(), pnt->Y(), pnt->Z()));
  }
  GeomAPI_Interpolate intp(pary, Standard_False, 1.0e-7);

  if (argc == 2) {
    TColgp_Array1OfVec vec(1, psize);
    Handle(TColStd_HArray1OfBoolean) use = new TColStd_HArray1OfBoolean(1, psize);

    for (int i=0; i<psize; i++) {
      mrb_value avec = mrb_ary_ref(mrb, vecs, i);
      if (mrb_nil_p(avec)) {
        use->SetValue(i+1, Standard_False); 
      }
      else {
        gp_Vec* vdir = siren_vec_get(mrb, avec);
        gp_Dir dir(vdir->X(), vdir->Y(), vdir->Z());
        vec.SetValue(i+1, dir);
        use->SetValue(i+1, Standard_True);
      }
    }
    intp.Load(vec, use, Standard_True);
  }

  intp.Perform();
  Handle(Geom_BSplineCurve) geSpl = intp.Curve();

  TopoDS_Shape* shape = new TopoDS_Shape();
  *shape = BRepBuilderAPI_MakeEdge(geSpl);

  return siren_shape_new(mrb, shape);
}

mrb_value siren_build_compound(mrb_state* mrb, mrb_value self)
{
  mrb_value ary;
  int argc = mrb_get_args(mrb, "A", &ary);

  TopoDS_Compound* comp = new TopoDS_Compound;
  BRep_Builder B;
  B.MakeCompound(*comp);

  for (int i = 0; i < mrb_ary_len(mrb, ary); i++) {
    TopoDS_Shape* shape = siren_shape_get(mrb, mrb_ary_ref(mrb, ary, i));
    B.Add(*comp, *shape);
  }

  return siren_shape_new(mrb, comp);
}

