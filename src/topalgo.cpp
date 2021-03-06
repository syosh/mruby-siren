#include "topalgo.h"

bool siren_topalgo_install(mrb_state* mrb, struct RClass* mod_siren)
{
  // Class method
  mrb_define_class_method(mrb, mod_siren, "copy",       siren_topalgo_copy,       MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
  mrb_define_class_method(mrb, mod_siren, "vertex",     siren_topalgo_vertex,     MRB_ARGS_OPT(1));
  mrb_define_class_method(mrb, mod_siren, "line",       siren_topalgo_line,       MRB_ARGS_OPT(2));
  mrb_define_class_method(mrb, mod_siren, "infline",    siren_topalgo_infline,    MRB_ARGS_OPT(2));
  mrb_define_class_method(mrb, mod_siren, "polyline",   siren_topalgo_polyline,   MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, mod_siren, "curve",      siren_topalgo_curve,      MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
  mrb_define_class_method(mrb, mod_siren, "wire",       siren_topalgo_wire,       MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
  mrb_define_class_method(mrb, mod_siren, "arc",        siren_topalgo_arc,        MRB_ARGS_REQ(6));
  mrb_define_class_method(mrb, mod_siren, "arc3p",      siren_topalgo_arc3p,      MRB_ARGS_REQ(3));
  mrb_define_class_method(mrb, mod_siren, "circle",     siren_topalgo_circle,     MRB_ARGS_REQ(3));
  mrb_define_class_method(mrb, mod_siren, "circle3p",   siren_topalgo_circle3p,   MRB_ARGS_REQ(3));
  mrb_define_class_method(mrb, mod_siren, "plane",      siren_topalgo_plane,      MRB_ARGS_REQ(7));
  mrb_define_class_method(mrb, mod_siren, "face",       siren_topalgo_face,       MRB_ARGS_REQ(2));
  mrb_define_class_method(mrb, mod_siren, "infplane",   siren_topalgo_infplane,   MRB_ARGS_REQ(2));
  mrb_define_class_method(mrb, mod_siren, "polygon",    siren_topalgo_polygon,    MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
  mrb_define_class_method(mrb, mod_siren, "nurbscurve", siren_topalgo_nurbscurve, MRB_ARGS_REQ(4) | MRB_ARGS_OPT(3));
  mrb_define_class_method(mrb, mod_siren, "beziersurf", siren_topalgo_beziersurf, MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
  mrb_define_class_method(mrb, mod_siren, "nurbssurf",  siren_topalgo_nurbssurf,  MRB_ARGS_REQ(5) | MRB_ARGS_OPT(1));
  mrb_define_class_method(mrb, mod_siren, "sewing",     siren_topalgo_sewing,     MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
  mrb_define_class_method(mrb, mod_siren, "shell",      siren_topalgo_sewing,     MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
  mrb_define_class_method(mrb, mod_siren, "solid",      siren_topalgo_solid,      MRB_ARGS_REQ(1));
  mrb_define_class_method(mrb, mod_siren, "compound",   siren_topalgo_compound,   MRB_ARGS_REQ(1));
  // For mix-in
  mrb_define_method      (mrb, mod_siren, "copy",       siren_topalgo_copy,       MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
  mrb_define_method      (mrb, mod_siren, "vertex",     siren_topalgo_vertex,     MRB_ARGS_REQ(1));
  mrb_define_method      (mrb, mod_siren, "line",       siren_topalgo_line,       MRB_ARGS_REQ(2));
  mrb_define_method      (mrb, mod_siren, "infline",    siren_topalgo_infline,    MRB_ARGS_REQ(2));
  mrb_define_method      (mrb, mod_siren, "polyline",   siren_topalgo_polyline,   MRB_ARGS_REQ(1));
  mrb_define_method      (mrb, mod_siren, "curve",      siren_topalgo_curve,      MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
  mrb_define_method      (mrb, mod_siren, "wire",       siren_topalgo_wire,       MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
  mrb_define_method      (mrb, mod_siren, "arc",        siren_topalgo_arc,        MRB_ARGS_REQ(6));
  mrb_define_method      (mrb, mod_siren, "arc3p",      siren_topalgo_arc3p,      MRB_ARGS_REQ(3));
  mrb_define_method      (mrb, mod_siren, "circle",     siren_topalgo_circle,     MRB_ARGS_REQ(3));
  mrb_define_method      (mrb, mod_siren, "circle3p",   siren_topalgo_circle3p,   MRB_ARGS_REQ(3));
  mrb_define_method      (mrb, mod_siren, "plane",      siren_topalgo_plane,      MRB_ARGS_REQ(7));
  mrb_define_method      (mrb, mod_siren, "face",       siren_topalgo_face,       MRB_ARGS_REQ(2));
  mrb_define_method      (mrb, mod_siren, "infplane",   siren_topalgo_infplane,   MRB_ARGS_REQ(2));
  mrb_define_method      (mrb, mod_siren, "polygon",    siren_topalgo_polygon,    MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
  mrb_define_method      (mrb, mod_siren, "nurbscurve", siren_topalgo_nurbscurve, MRB_ARGS_REQ(4) | MRB_ARGS_OPT(3));
  mrb_define_method      (mrb, mod_siren, "beziersurf", siren_topalgo_beziersurf, MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
  mrb_define_method      (mrb, mod_siren, "nurbssurf",  siren_topalgo_nurbssurf,  MRB_ARGS_REQ(5) | MRB_ARGS_OPT(1));
  mrb_define_method      (mrb, mod_siren, "sewing",     siren_topalgo_sewing,     MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
  mrb_define_method      (mrb, mod_siren, "shell",      siren_topalgo_sewing,     MRB_ARGS_REQ(1) | MRB_ARGS_OPT(1));
  mrb_define_method      (mrb, mod_siren, "solid",      siren_topalgo_solid,      MRB_ARGS_REQ(1));
  mrb_define_method      (mrb, mod_siren, "compound",   siren_topalgo_compound,   MRB_ARGS_REQ(1));

  struct RClass* cls_shape = siren_shape_rclass(mrb);
  mrb_define_method      (mrb, cls_shape, "volume",  siren_topalgo_volume,     MRB_ARGS_NONE());
  mrb_define_method      (mrb, cls_shape, "cog",     siren_topalgo_cog,        MRB_ARGS_NONE());
  mrb_define_method      (mrb, cls_shape, "area",    siren_topalgo_area,       MRB_ARGS_NONE());
  return true;
}

mrb_value siren_topalgo_copy(mrb_state* mrb, mrb_value self)
{
  mrb_value target;
  mrb_bool copy_geom;
  int argc = mrb_get_args(mrb, "o|b", &target, &copy_geom);
  if (argc < 2) {
    copy_geom = true;
  }
  TopoDS_Shape* src = siren_shape_get(mrb, target);
  TopoDS_Shape res = BRepBuilderAPI_Copy(*src, (Standard_Boolean)copy_geom);
  return siren_shape_new(mrb, res);
}

mrb_value siren_topalgo_vertex(mrb_state* mrb, mrb_value self)
{
  mrb_value pos;
  int argc = mrb_get_args(mrb, "|A", &pos);
  gp_Pnt pnt(0., 0., 0.);
  if (argc) {
    pnt = siren_ary_to_pnt(mrb, pos);
  }
  TopoDS_Shape shape = BRepBuilderAPI_MakeVertex(pnt);
  return siren_shape_new(mrb, shape);
}

mrb_value siren_topalgo_line(mrb_state* mrb, mrb_value self)
{
  mrb_value sp, tp;
  int argc = mrb_get_args(mrb, "|AA", &sp, &tp);
  gp_Pnt S(0., 0., 0.);
  gp_Pnt T(1., 1., 1.);
  if (argc > 0) {
    S = siren_ary_to_pnt(mrb, sp);
  }
  if (argc > 1) {
    T = siren_ary_to_pnt(mrb, tp);
  }
  TopoDS_Shape shape = BRepBuilderAPI_MakeEdge(S, T);
  return siren_shape_new(mrb, shape);
}

mrb_value siren_topalgo_infline(mrb_state* mrb, mrb_value self)
{
  mrb_value orig, dir;
  int argc = mrb_get_args(mrb, "|AA", &orig, &dir);
  gp_Pnt p(0., 0., 0.);
  gp_Dir d(1., 0., 0.);
  if (argc > 0) {
    p = siren_ary_to_pnt(mrb, orig);
  }
  if (argc > 1) {
    d = siren_ary_to_dir(mrb, dir);
  }
  TopoDS_Shape shape = BRepBuilderAPI_MakeEdge(gp_Lin(p, d));
  return siren_shape_new(mrb, shape);
}

mrb_value siren_topalgo_polyline(mrb_state* mrb, mrb_value self)
{
  mrb_value ary;
  int argc = mrb_get_args(mrb, "A", &ary);
  BRepBuilderAPI_MakePolygon poly;
  for (int i = 0; i < mrb_ary_len(mrb, ary); i++) {
    poly.Add(siren_ary_to_pnt(mrb, mrb_ary_ref(mrb, ary, i)));
  }
  TopoDS_Shape shape = poly.Wire();
  return siren_shape_new(mrb, shape);
}

mrb_value siren_topalgo_curve(mrb_state* mrb, mrb_value self)
{
  mrb_value pts, vecs;
  int argc = mrb_get_args(mrb, "A|A", &pts, &vecs);

  int psize = mrb_ary_len(mrb, pts);
  Handle(TColgp_HArray1OfPnt) pary = new TColgp_HArray1OfPnt(1, psize);
  for (int i=0; i<psize; i++) {
    pary->SetValue(i+1, siren_ary_to_pnt(mrb, mrb_ary_ref(mrb, pts, i)));
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
        vec.SetValue(i+1, siren_ary_to_vec(mrb, avec));
        use->SetValue(i+1, Standard_True);
      }
    }
    intp.Load(vec, use, Standard_True);
  }

  intp.Perform();
  Handle(Geom_BSplineCurve) geSpl = intp.Curve();

  if (geSpl.IsNull()) {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Failed to make a curve.");
    return mrb_nil_value();
  }
  else {
    TopoDS_Shape shape = BRepBuilderAPI_MakeEdge(geSpl);
    return siren_shape_new(mrb, shape);
  }
}

mrb_value siren_topalgo_wire(mrb_state* mrb, mrb_value self)
{
  mrb_value objs;
  mrb_float tol;
  int argc = mrb_get_args(mrb, "A|f", &objs, &tol);
  ShapeFix_Wire sfw;
  Handle(ShapeExtend_WireData) wd = new ShapeExtend_WireData();
  BRepBuilderAPI_MakeWire mw;
  ShapeFix_ShapeTolerance FTol;
  int osize = mrb_ary_len(mrb, objs);
  for (int i = 0; i < osize ; i++) {
    mrb_value obj = mrb_ary_ref(mrb, objs, i);
    TopoDS_Shape* s = siren_shape_get(mrb, obj);
    if (s->IsNull()) {
      continue;
    }
    TopExp_Explorer exp(*s, TopAbs_EDGE);
    for (; exp.More(); exp.Next()) {
      wd->Add(TopoDS::Edge(exp.Current()));
    }
  }
  if (wd->NbEdges() == 0) {
    return mrb_nil_value();
  }
  sfw.Load(wd);
  sfw.Perform();
  for (int i = 1; i <= sfw.NbEdges(); i ++) {
    TopoDS_Edge e = sfw.WireData()->Edge(i);
    FTol.SetTolerance(e, argc == 1 ? 0.01 : tol, TopAbs_VERTEX);
    mw.Add(e);
  }

  return siren_shape_new(mrb, mw.Shape());
}

mrb_value siren_topalgo_arc(mrb_state* mrb, mrb_value self)
{
  mrb_value orig, dir, vx;
  mrb_float r, start_ang, term_ang;
  int argc = mrb_get_args(mrb, "AAAfff", &orig, &dir, &vx, &r, &start_ang, &term_ang);
  gp_Circ circle = gp_Circ(gp_Ax2(siren_ary_to_pnt(mrb, orig), siren_ary_to_dir(mrb, dir), siren_ary_to_dir(mrb, vx)), r);
  Handle(Geom_TrimmedCurve) gc = GC_MakeArcOfCircle(circle, start_ang, term_ang, Standard_True);
  if (gc.IsNull()) {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Failed to make a curve.");
    return mrb_nil_value();
  }
  else {
    TopoDS_Edge E = BRepBuilderAPI_MakeEdge(gc);
    return siren_shape_new(mrb, E);
  }
}

mrb_value siren_topalgo_arc3p(mrb_state* mrb, mrb_value self)
{
  mrb_value p1, p2, p3;
  int argc = mrb_get_args(mrb, "AAA", &p1, &p2, &p3);
  Handle(Geom_TrimmedCurve) gc = GC_MakeArcOfCircle(
      siren_ary_to_pnt(mrb, p1),
      siren_ary_to_pnt(mrb, p2),
      siren_ary_to_pnt(mrb, p3));
  if (gc.IsNull()) {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Failed to make a curve.");
    return mrb_nil_value();
  }
  else {
    TopoDS_Edge E = BRepBuilderAPI_MakeEdge(gc);
    return siren_shape_new(mrb, E);
  }
}

mrb_value siren_topalgo_circle(mrb_state* mrb, mrb_value self)
{
  mrb_value orig, dir;
  mrb_float r;
  int argc = mrb_get_args(mrb, "AAf", &orig, &dir, &r);
  Handle(Geom_Circle) gc = GC_MakeCircle(
      siren_ary_to_pnt(mrb, orig),
      siren_ary_to_dir(mrb, dir),
      r);
  if (gc.IsNull()) {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Failed to make a curve.");
    return mrb_nil_value();
  }
  else {
    TopoDS_Edge E = BRepBuilderAPI_MakeEdge(gc);
    return siren_shape_new(mrb, E);
  }
}

mrb_value siren_topalgo_circle3p(mrb_state* mrb, mrb_value self)
{
  mrb_value p1, p2, p3;
  int argc = mrb_get_args(mrb, "AAA", &p1, &p2, &p3);
  Handle(Geom_Circle) gc = GC_MakeCircle(
      siren_ary_to_pnt(mrb, p1),
      siren_ary_to_pnt(mrb, p2),
      siren_ary_to_pnt(mrb, p3));
  if (gc.IsNull()) {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Failed to make a curve.");
    return mrb_nil_value();
  }
  else {
    TopoDS_Edge E = BRepBuilderAPI_MakeEdge(gc);
    return siren_shape_new(mrb, E);
  }
}

mrb_value siren_topalgo_plane(mrb_state* mrb, mrb_value self)
{
  mrb_value pos, norm, vdir;
  mrb_float umin, umax, vmin, vmax;
  int argc = mrb_get_args(mrb, "AAAffff", &pos, &norm, &vdir, &umin, &umax, &vmin, &vmax);
  gp_Pln _pln(siren_ary_to_ax2(mrb, pos, norm, vdir));
  BRepBuilderAPI_MakeFace face(_pln, umin, umax, vmin, vmax);
  return siren_shape_new(mrb, face.Shape());
}

mrb_value siren_topalgo_face(mrb_state* mrb, mrb_value self)
{
  mrb_value wire;
  mrb_bool force_plane;
  int argc = mrb_get_args(mrb, "ob", &wire, &force_plane);
  TopoDS_Shape* s = siren_shape_get(mrb, wire);
  TopoDS_Wire w = TopoDS::Wire(*s);
  if (w.IsNull()) {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Specified shape type is not wire.");
  }
  TopoDS_Face face = BRepBuilderAPI_MakeFace(w, (Standard_Boolean)force_plane);
  return siren_shape_new(mrb, face);
}

mrb_value siren_topalgo_infplane(mrb_state* mrb, mrb_value self)
{
  mrb_value orig, dir;
  int argc = mrb_get_args(mrb, "AA", &orig, &dir);
  gp_Pln pln(siren_ary_to_pnt(mrb, orig), siren_ary_to_dir(mrb, dir));
  TopoDS_Face face = BRepBuilderAPI_MakeFace(pln);
  return siren_shape_new(mrb, face);
}

mrb_value siren_topalgo_polygon(mrb_state* mrb, mrb_value self)
{
  mrb_value pts;
  mrb_bool force_plane;
  int argc = mrb_get_args(mrb, "A|b", &pts, &force_plane);
  if (argc < 2) {
    force_plane = true;
  }

  BRepBuilderAPI_MakePolygon mp;

  for (int i=0; i<mrb_ary_len(mrb, pts); i++) {
    mp.Add(siren_ary_to_pnt(mrb, mrb_ary_ref(mrb, pts, i)));
  }

  mp.Close();
  BRepBuilderAPI_MakeFace mf(mp.Wire(), force_plane);
  mf.Build();

  if (!mf.IsDone()) {
    mrb_raise(mrb, E_ARGUMENT_ERROR, "Failed to make a polygon.");
  }

  return siren_shape_new(mrb, mf.Shape());
}

mrb_value siren_topalgo_nurbscurve(mrb_state* mrb, mrb_value self)
{
  mrb_int d;
  mrb_value ks, ms, ps, ws;
  mrb_float first, last;
  int argc = mrb_get_args(mrb, "iAAA|Aff", &d, &ks, &ms, &ps, &ws, &first, &last);

  int plen = mrb_ary_len(mrb, ps);

  TColgp_Array1OfPnt poles(0, plen - 1);
  TColStd_Array1OfReal weights(0, plen - 1);
  for (int i=0; i < plen; i++) {
    poles.SetValue(i, siren_ary_to_pnt(mrb, mrb_ary_ref(mrb, ps, i)));
    if (argc >= 5) {
      mrb_value w = mrb_ary_ref(mrb, ws, i);
      weights.SetValue(i, mrb_float(w));
    }
    else {
      weights.SetValue(i, 1.0);
    }
  }

  int klen = mrb_ary_len(mrb, ks);
  TColStd_Array1OfReal knots(0, klen - 1);
  TColStd_Array1OfInteger mults(0, klen - 1);

  for (int i=0; i < klen; i++) {
    mrb_value knot = mrb_ary_ref(mrb, ks, i);
    knots.SetValue(i, mrb_float(knot));
    mrb_value mult = mrb_ary_ref(mrb, ms, i);
    mults.SetValue(i, (Standard_Integer)mrb_fixnum(mult));
  }

  Handle(Geom_BSplineCurve) hgeom_bscurve = new Geom_BSplineCurve(
      poles, weights, knots, mults, (Standard_Integer)d, Standard_False);

  if (argc == 7)
    return siren_shape_new(mrb, BRepBuilderAPI_MakeEdge(hgeom_bscurve, first, last));
  else
    return siren_shape_new(mrb, BRepBuilderAPI_MakeEdge(hgeom_bscurve));
}

mrb_value siren_topalgo_beziersurf(mrb_state* mrb, mrb_value self)
{
  mrb_value ptary, wtary;
  int argc = mrb_get_args(mrb, "A|A", &ptary, &wtary);

  int rlen = mrb_ary_len(mrb, ptary);
  int clen = mrb_ary_len(mrb, mrb_ary_ref(mrb, ptary, 0));

  TColgp_Array2OfPnt poles(0, rlen-1, 0, clen-1);

  for (int r=0; r<rlen; r++) {
    mrb_value ar = mrb_ary_ref(mrb, ptary, r);
    for (int c=0; c<clen; c++) {
      poles.SetValue(r, c, siren_ary_to_pnt(mrb, mrb_ary_ref(mrb, ar, c)));
    }
  }

  Handle(Geom_BezierSurface) s = NULL;

  if (argc == 2) {
    TColStd_Array2OfReal weights(0, rlen-1, 0, clen-1);
    for (int r=0; r<rlen; r++) {
      mrb_value ar = mrb_ary_ref(mrb, wtary, r);
      for (int c=0; c<clen; c++) {
        mrb_value val = mrb_ary_ref(mrb, ar, c);
        weights.SetValue(r, c, mrb_float(val));
      }
    }
    s = new Geom_BezierSurface(poles, weights);
  }
  else {
    s = new Geom_BezierSurface(poles);
  }

  return siren_shape_new(mrb, BRepBuilderAPI_MakeFace(s, 1.0e-7));
}

mrb_value siren_topalgo_nurbssurf(mrb_state* mrb, mrb_value self)
{
  mrb_int _udeg, _vdeg;
  mrb_value _ar_ukm, _ar_vkm;
  mrb_value _pol;
  mrb_value _wire;
  int argc = mrb_get_args(mrb, "iAiAA|o", &_udeg, &_ar_ukm, &_vdeg, &_ar_vkm, &_pol, &_wire);

  bool has_contour = argc == 6;

  Standard_Integer udeg = _udeg;
  Standard_Integer nbuknots = mrb_ary_len(mrb, _ar_ukm);
  Standard_Integer nbuknots_pure = 0;
  TColStd_Array1OfReal uknots(1, nbuknots);
  TColStd_Array1OfInteger umults(1, nbuknots);
  for (int i=1; i<=nbuknots; i++) {
    mrb_value item = mrb_ary_ref(mrb, _ar_ukm, i - 1);
    mrb_value knot = mrb_ary_ref(mrb, item, 0);
    mrb_value mult = mrb_ary_ref(mrb, item, 1);
    uknots(i) = mrb_float(knot);
    umults(i) = mrb_fixnum(mult);
    nbuknots_pure += umults(i);
  }
  Standard_Integer nbupoles = nbuknots_pure - udeg - 1;

  Standard_Integer vdeg = _vdeg;
  Standard_Integer nbvknots = mrb_ary_len(mrb, _ar_vkm);
  Standard_Integer nbvknots_pure = 0;
  TColStd_Array1OfReal vknots(1, nbvknots);
  TColStd_Array1OfInteger vmults(1, nbvknots);
  for (int i=1; i<=nbvknots; i++) {
    mrb_value item = mrb_ary_ref(mrb, _ar_vkm, i - 1);
    mrb_value knot = mrb_ary_ref(mrb, item, 0);
    mrb_value mult = mrb_ary_ref(mrb, item, 1);
    vknots(i) = mrb_float(knot);
    vmults(i) = mrb_fixnum(mult);
    nbvknots_pure += vmults(i);
  }
  Standard_Integer nbvpoles = nbvknots_pure - vdeg - 1;

  TColgp_Array2OfPnt   poles  (1, nbupoles, 1, nbvpoles);
  TColStd_Array2OfReal weights(1, nbupoles, 1, nbvpoles);

  for (int v=1; v <= nbvpoles; v++) {
    mrb_value vitem = mrb_ary_ref(mrb, _pol, v - 1);
    for (int u=1; u <= nbupoles; u++) {
      mrb_value uitem = mrb_ary_ref(mrb, vitem, u - 1);
      poles.SetValue(u, v, siren_ary_to_pnt(mrb, mrb_ary_ref(mrb, uitem, 0)));
      weights.SetValue(u, v, mrb_float(mrb_ary_ref(mrb, uitem, 1)));
    }
  }

  Handle(Geom_BSplineSurface) hg_bssurf = new Geom_BSplineSurface(poles, weights, uknots, vknots, umults, vmults, udeg, vdeg);
  TopoDS_Shape shape;
  if (has_contour) {
    TopoDS_Shape* s = siren_shape_get(mrb, _wire);
    TopoDS_Wire w = TopoDS::Wire(*s);
    shape = BRepBuilderAPI_MakeFace(hg_bssurf, w, Standard_True);
    // Fix a face
    Handle(ShapeFix_Shape) sfs = new ShapeFix_Shape();
    sfs->Init(shape);
    sfs->FixFaceTool()->FixAddNaturalBoundMode() = 1;
    sfs->FixFaceTool()->FixIntersectingWiresMode() = 1;
    sfs->FixFaceTool()->FixLoopWiresMode() = 1;
    sfs->FixFaceTool()->FixOrientationMode() = 1;
    sfs->FixFaceTool()->FixPeriodicDegeneratedMode() = 1;
    sfs->FixFaceTool()->FixSmallAreaWireMode() = 1;
    sfs->FixFaceTool()->FixSplitFaceMode() = 1;
    sfs->FixFaceTool()->FixWireMode() = 1;
    sfs->SetPrecision(1.0);
    sfs->SetMinTolerance(1.0e-1);
    sfs->SetMaxTolerance(1.0);
    sfs->Perform();
    shape = sfs->Shape();
    // End of fix
  }
  else {
    Standard_Real toldegen = 1.0e-1;
    shape = BRepBuilderAPI_MakeFace(hg_bssurf, toldegen);
  }

  return siren_shape_new(mrb, shape);
}

mrb_value siren_topalgo_sewing(mrb_state* mrb, mrb_value self)
{
  mrb_value ar;
  mrb_float tol;
  int argc = mrb_get_args(mrb, "A|f", &ar, &tol);

  BRepBuilderAPI_Sewing sewer;
  sewer.Init();
  if (argc == 2 && tol >= 0) {
    sewer.SetTolerance(tol);
  }

  int psize = mrb_ary_len(mrb, ar);
  for (int i=0; i<psize; i++) {
    mrb_value item = mrb_ary_ref(mrb, ar, i);
    TopoDS_Shape* shape = siren_shape_get(mrb, item);
    if (shape->IsNull()) {
      continue;
    }
    TopExp_Explorer ex(*shape, TopAbs_FACE);
    for (; ex.More(); ex.Next()) {
      sewer.Add(ex.Current());
    }
  }

  sewer.Perform();

  return siren_shape_new(mrb, sewer.SewedShape());
}

mrb_value siren_topalgo_solid(mrb_state* mrb, mrb_value self)
{
  mrb_value obj;
  int argc = mrb_get_args(mrb, "o", &obj);

  TopoDS_Shape* shape = siren_shape_get(mrb, obj);

  BRepBuilderAPI_MakeSolid solid_maker;

  for (TopExp_Explorer ex(*shape, TopAbs_SHELL); ex.More(); ex.Next()) {
    TopoDS_Shell shell = TopoDS::Shell(ex.Current());
    solid_maker.Add(shell);
  }
  if (!solid_maker.IsDone())
    return mrb_nil_value();

  return siren_shape_new(mrb, solid_maker.Solid());
}

mrb_value siren_topalgo_compound(mrb_state* mrb, mrb_value self)
{
  mrb_value ary;
  int argc = mrb_get_args(mrb, "A", &ary);

  TopoDS_Compound comp;
  BRep_Builder B;
  B.MakeCompound(comp);

  for (int i = 0; i < mrb_ary_len(mrb, ary); i++) {
    TopoDS_Shape* shape = siren_shape_get(mrb, mrb_ary_ref(mrb, ary, i));
    B.Add(comp, *shape);
  }

  return siren_shape_new(mrb, comp);
}

mrb_value siren_topalgo_volume(mrb_state* mrb, mrb_value self)
{
  TopoDS_Shape* shape = siren_shape_get(mrb, self);
  GProp_GProps gprops;
  BRepGProp::VolumeProperties(*shape, gprops);
  Standard_Real vol = gprops.Mass();
  return mrb_float_value(mrb, (mrb_float)vol);
}

mrb_value siren_topalgo_cog(mrb_state* mrb, mrb_value self)
{
  TopoDS_Shape* shape = siren_shape_get(mrb, self);
  GProp_GProps gprops;
  BRepGProp::VolumeProperties(*shape, gprops);
  gp_Pnt cog = gprops.CentreOfMass();
  return siren_pnt_to_ary(mrb, cog);
}

mrb_value siren_topalgo_area(mrb_state* mrb, mrb_value self)
{
  TopoDS_Shape* shape = siren_shape_get(mrb, self);
  GProp_GProps gprops;
  BRepGProp::SurfaceProperties(*shape, gprops);
  Standard_Real area = gprops.Mass();
  return mrb_float_value(mrb, area);
}

