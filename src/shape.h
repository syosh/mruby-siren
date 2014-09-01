#ifndef _SHAPE_H_
#define _SHAPE_H_

#include "siren.h"
#include "vec.h"

void siren_shape_final(mrb_state* mrb, void* p);
bool siren_shape_install(mrb_state* mrb, struct RClass* rclass);
static struct mrb_data_type siren_shape_type = { "Shape", siren_shape_final };
TopoDS_Shape* siren_shape_get(mrb_state* mrb, mrb_value obj);
mrb_value siren_shape_new(mrb_state* mrb, const TopoDS_Shape* shape);

mrb_value siren_shape_init(mrb_state* mrb, mrb_value self);
mrb_value siren_shape_to_s(mrb_state* mrb, mrb_value self);
mrb_value siren_shape_is_null(mrb_state* mrb, mrb_value self);
mrb_value siren_shape_shapetype(mrb_state* mrb, mrb_value self);
mrb_value siren_shape_location(mrb_state* mrb, mrb_value self);

mrb_value siren_shape_translate(mrb_state* mrb, mrb_value self);

#endif
