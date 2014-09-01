#include "offset.h"

bool siren_offset_install(mrb_state* mrb, struct RClass* rclass)
{
  rclass = mrb_define_module(mrb, "Offset");
  mrb_define_class_method(mrb, rclass, "sweep_vec", siren_offset_sweep_vec, ARGS_REQ(2));
  mrb_define_class_method(mrb, rclass, "sweep_path", siren_offset_sweep_path, ARGS_REQ(2) | ARGS_OPT(4));
  return true;
}

mrb_value siren_offset_sweep_vec(mrb_state* mrb, mrb_value self)
{
  mrb_value target, vec;
  int argc = mrb_get_args(mrb, "oA", &target, &vec);

  TopoDS_Shape* profile = siren_shape_get(mrb, target);

  gp_Vec* _vec = siren_vec_get(mrb, vec);
  gp_Pnt _pt = gp_Pnt(0., 0., 0.).Transformed(profile->Location());

  TopoDS_Edge pe = BRepBuilderAPI_MakeEdge(_pt, gp_Pnt(_vec->X(), _vec->Y(), _vec->Z()));
  TopoDS_Wire path = BRepBuilderAPI_MakeWire(pe);

  BRepOffsetAPI_MakePipe mp(path, *profile);
  mp.Build();

  TopoDS_Shape* shape = new TopoDS_Shape();
  *shape = mp.Shape();

  return siren_shape_new(mrb, shape);
}

mrb_value siren_offset_sweep_path(mrb_state* mrb, mrb_value self)
{

  mrb_value target, pathwire;
  mrb_value cont, corr;
  mrb_float scale_first, scale_last;
  int argc = mrb_get_args(mrb, "oo|ooff", &target, &pathwire, &cont, &corr, &scale_first, &scale_last);

  TopoDS_Shape* shape_profile = siren_shape_get(mrb, target);
  TopoDS_Shape* shape_path = siren_shape_get(mrb, pathwire);

  TopoDS_Wire path;

  if (shape_path->ShapeType() == TopAbs_EDGE) {
    path = BRepBuilderAPI_MakeWire(TopoDS::Edge(*shape_path));
  }
  else if (shape_path->ShapeType() == TopAbs_WIRE) {
    path = TopoDS::Wire(*shape_path);
  }
  else {
    static const char m[] = "Path object is not Edge or Wire.";
    return mrb_exc_new(mrb, E_ARGUMENT_ERROR, m, sizeof(m) - 1);
  }

  mrb_value result = mrb_nil_value();

  if (argc >= 3 && argc <= 6) {

    Standard_Boolean withContact = (Standard_Boolean)mrb_test(cont);
    Standard_Boolean withCorrection = (Standard_Boolean)mrb_test(corr);

    BRepOffsetAPI_MakePipeShell ps(path);

    // get params
    Standard_Real fparam, lparam;
    {
      BRepAdaptor_CompCurve cc(path);
      fparam = cc.FirstParameter();
      lparam = cc.LastParameter();
    }

    if (argc < 6) {
      scale_last  = 1.0;
      if (argc < 5) {
        scale_first = 1.0;
      }
    }

    //Handle(Law_Linear) law = new Law_Linear();
    //law->Set(fparam, scale_first, lparam, scale_last);

    Handle(Law_S) law = new Law_S();
    law->Set(fparam, scale_first, lparam, scale_last);

    //Handle(Law_Composite) law = new Law_Composite(fparam, lparam, 1.0e-6);

    // get start point
    TopoDS_Vertex pfirst; {
      TopoDS_Vertex plast;
      TopExp::Vertices(path, pfirst, plast);
    }

    ps.SetLaw(
        *shape_profile, // セクションプロファイル
        law,           // 掃引規則
        pfirst,        // 開始点
        withContact,   // セクションプロファイルを開始点に移動して掃引する
        withCorrection // セクションプロファイルをパスに応じて回転する
        );

    ps.Build();
    TopoDS_Shape* shape = new TopoDS_Shape();
    *shape = ps.Shape();
    result = siren_shape_new(mrb, shape);
  }
  else {
    BRepOffsetAPI_MakePipe mp(path, *shape_profile);
    mp.Build();
    TopoDS_Shape* shape = new TopoDS_Shape();
    *shape = mp.Shape();
    result = siren_shape_new(mrb, shape);
  }
  return result;
}
