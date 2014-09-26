#include "skin.h"

//Handle(AIS_Shape) siren_skin_get(mrb_state* mrb, mrb_value obj)
AIS_Shape* siren_skin_get(mrb_state* mrb, mrb_value obj)
{
  void* p = mrb_get_datatype(mrb, obj, &siren_skin_type);
  //return static_cast<const AIS_Shape* /* Handle(AIS_Shape) */>(p);
  return static_cast<AIS_Shape*>(p);
}

bool siren_skin_install(mrb_state* mrb, struct RClass* rclass)
{
  rclass = mrb_define_class(mrb, "Skin", mrb->object_class);
  MRB_SET_INSTANCE_TT(rclass, MRB_TT_DATA);
  mrb_define_method(mrb, rclass, "initialize", siren_skin_init,       ARGS_NONE());

  return true;
}

mrb_value siren_skin_init(mrb_state* mrb, mrb_value self)
{
  mrb_value shape;
  int argc = mrb_get_args(mrb, "o", &shape);
  TopoDS_Shape* pshape = siren_shape_get(mrb, shape);

#if 0
  void* p = mrb_malloc(mrb, sizeof(AIS_Shape));
  Handle(AIS_Shape) hashape = new(p) AIS_Shape(*pshape);
#else
  // Handle(AIS_Shape) hashape = new AIS_Shape(*pshape);
  AIS_Shape* hashape = new AIS_Shape(*pshape);
#endif

  DATA_PTR(self) = hashape;
  DATA_TYPE(self) = &siren_skin_type;

  return self;
}

void siren_skin_final(mrb_state* mrb, void* p)
{
  //Handle(AIS_Shape) s = static_cast<Handle(AIS_Shape)>(p);
  //mrb_free(mrb, s);
}
