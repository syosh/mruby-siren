#include "singleton_edge.h"

void siren_edge_install(mrb_state* mrb, RObject* o)
{
  mrb_define_singleton_method(mrb, o, "sp",        siren_edge_sp,        MRB_ARGS_NONE());
  mrb_define_singleton_method(mrb, o, "tp",        siren_edge_tp,        MRB_ARGS_NONE());
  mrb_define_singleton_method(mrb, o, "to_pts",    siren_edge_to_pts,    MRB_ARGS_OPT(1));
  mrb_define_singleton_method(mrb, o, "param",     siren_edge_param,     MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
  mrb_define_singleton_method(mrb, o, "to_xyz",    siren_edge_to_xyz,    MRB_ARGS_REQ(1));
  mrb_define_singleton_method(mrb, o, "curvature", siren_edge_curvature, MRB_ARGS_REQ(1));
  mrb_define_singleton_method(mrb, o, "tangent",   siren_edge_tangent,   MRB_ARGS_REQ(1));
  mrb_define_singleton_method(mrb, o, "nurbs_def", siren_edge_nurbs_def, MRB_ARGS_NONE());
  return;
}

mrb_value siren_edge_sp(mrb_state* mrb, mrb_value self)
{
  TopoDS_Shape* c = siren_shape_get(mrb, self);
  BRepAdaptor_Curve bracurve(TopoDS::Edge(*c));
  gp_Pnt sp = bracurve.Value(bracurve.FirstParameter());
  return siren_vec_new(mrb, sp.X(), sp.Y(), sp.Z());
}

mrb_value siren_edge_tp(mrb_state* mrb, mrb_value self)
{
  TopoDS_Shape* c = siren_shape_get(mrb, self);
  BRepAdaptor_Curve bracurve(TopoDS::Edge(*c));
  gp_Pnt tp = bracurve.Value(bracurve.LastParameter());
  return siren_vec_new(mrb, tp.X(), tp.Y(), tp.Z());
}

mrb_value siren_edge_to_pts(mrb_state* mrb, mrb_value self)
{
  mrb_float deflect;
  int argc = mrb_get_args(mrb, "|f", &deflect);

  TopoDS_Shape* shape = siren_shape_get(mrb, self);

  if (argc != 2) {
    deflect = 1.0e-1;
  }

  mrb_value result = mrb_ary_new(mrb);
  double first_param, last_param;

  TopExp_Explorer exp(*shape, TopAbs_EDGE);
  for(; exp.More(); exp.Next()) {
    TopoDS_Edge edge = TopoDS::Edge(exp.Current());

    BRepAdaptor_Curve adaptor(edge);
    first_param = adaptor.FirstParameter();
    last_param = adaptor.LastParameter();

    GCPnts_UniformDeflection unidef(adaptor, deflect);
    if (!unidef.IsDone()) {
      continue;
    }

    mrb_value line = mrb_ary_new(mrb);

    // first point
    gp_Pnt p = adaptor.Value(first_param);
    mrb_ary_push(mrb, line, siren_vec_new(mrb, p.X(), p.Y(), p.Z()));

    for (int i=1; i<=unidef.NbPoints(); i++) {
      p = unidef.Value(i);
      mrb_ary_push(mrb, line, siren_vec_new(mrb, p.X(), p.Y(), p.Z()));
    }

    // last point
    p = adaptor.Value(last_param);
    mrb_ary_push(mrb, line, siren_vec_new(mrb, p.X(), p.Y(), p.Z()));

    mrb_ary_push(mrb, result, line);
  }

  return result;
}

mrb_value siren_edge_param(mrb_state* mrb, mrb_value self)
{
  mrb_value xyz;
  mrb_float tol;
  int argc = mrb_get_args(mrb, "o|f", &xyz, &tol);

  TopoDS_Shape* shape = siren_shape_get(mrb, self);
  TopoDS_Edge edge = TopoDS::Edge(*shape);

  ShapeAnalysis_Curve ana;
  BRepAdaptor_Curve gcurve(edge);
  gp_Pnt p = siren_pnt_get(mrb, xyz);
  gp_Pnt pp;
  Standard_Real param;
  Standard_Real distance = ana.Project(gcurve, p, tol, pp, param);

  if (fabs(distance) > tol) {
    static const char m[] = "Specified position is not on the edge.";
    return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
  }

  return mrb_float_value(mrb, param);
}

mrb_value siren_edge_to_xyz(mrb_state* mrb, mrb_value self)
{
  mrb_float param;
  int argc = mrb_get_args(mrb, "f", &param);
  TopoDS_Shape* shape = siren_shape_get(mrb, self);
  BRepAdaptor_Curve C(TopoDS::Edge(*shape));
  gp_Pnt p;
  gp_Vec v1, v2;
  C.D2(param, p, v1, v2);
  return siren_vec_new(mrb, p.X(), p.Y(), p.Z());
}

mrb_value siren_edge_curvature(mrb_state* mrb, mrb_value self)
{
  mrb_float param;
  int argc = mrb_get_args(mrb, "f", &param);
  TopoDS_Shape* shape = siren_shape_get(mrb, self);
  BRepAdaptor_Curve C(TopoDS::Edge(*shape));
  gp_Pnt p;
  gp_Vec v1, v2;
  C.D2(param, p, v1, v2);
  return siren_vec_new(mrb, v2.X(), v2.Y(), v2.Z());
}

mrb_value siren_edge_tangent(mrb_state* mrb, mrb_value self)
{
  mrb_float param;
  int argc = mrb_get_args(mrb, "f", &param);
  TopoDS_Shape* shape = siren_shape_get(mrb, self);
  BRepAdaptor_Curve C(TopoDS::Edge(*shape));
  gp_Pnt p;
  gp_Vec v1, v2;
  C.D2(param, p, v1, v2);
  return siren_vec_new(mrb, v1.X(), v1.Y(), v1.Z());
}

mrb_value siren_edge_nurbs_def(mrb_state* mrb, mrb_value self)
{
  TopoDS_Shape* shape = siren_shape_get(mrb, self);
  TopoDS_Edge edge = TopoDS::Edge(*shape);
  Standard_Real first, last;
  Handle(Geom_Curve) hgcurve = BRep_Tool::Curve(edge, first, last);
#if 0
  Handle(Geom_TrimmedCurve) hgtc = new Geom_TrimmedCurve(hgcurve, first, last);
  Handle(Geom_BSplineCurve) hgbc = Handle(Geom_BSplineCurve)::DownCast(hgtc->BasisCurve());
#else
  Handle(Geom_BSplineCurve) hgbc = Handle(Geom_BSplineCurve)::DownCast(hgcurve);
#endif
  if (hgbc.IsNull()) {
    // Failed to downcast to BSplineCurve
    return mrb_nil_value();
  }
  mrb_value res = mrb_ary_new(mrb);
  // degree
  mrb_ary_push(mrb, res, mrb_fixnum_value((int)hgbc->Degree()));
  // knots
  mrb_value knots = mrb_ary_new(mrb);
  for (int i=1; i <= hgbc->NbKnots(); i++) {
    mrb_ary_push(mrb, knots, mrb_float_value(mrb, hgbc->Knot(i)));
  }
  mrb_ary_push(mrb, res, knots);
  // mults
  mrb_value mults = mrb_ary_new(mrb);
  for (int i=1; i <= hgbc->NbKnots(); i++) {
    mrb_ary_push(mrb, mults, mrb_fixnum_value(hgbc->Multiplicity(i)));
  }
  mrb_ary_push(mrb, res, mults);
  // poles
  mrb_value poles = mrb_ary_new(mrb);
  for (int i=1; i <= hgbc->NbPoles(); i++) {
    mrb_ary_push(mrb, poles, siren_vec_new(mrb, hgbc->Pole(i).X(), hgbc->Pole(i).Y(), hgbc->Pole(i).Z()));
  }
  mrb_ary_push(mrb, res, poles);
  // weights
  mrb_value weights = mrb_ary_new(mrb);
  for (int i=1; i <= hgbc->NbPoles(); i++) {
    mrb_ary_push(mrb, weights, mrb_float_value(mrb, hgbc->Weight(i)));
  }
  mrb_ary_push(mrb, res, weights);
  return res;
}

