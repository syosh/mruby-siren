#ifndef _BUILD_H_
#define _BUILD_H_

#include "siren.h"
#include "vec.h"
#include "shape.h"

#include <BRep_Builder.hxx>
#include <BRepBuilderAPI.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakePolygon.hxx>

bool siren_build_install(mrb_state* mrb, struct RClass* rclass);

mrb_value siren_build_vertex(mrb_state* mrb, mrb_value self);

mrb_value siren_build_line(mrb_state* mrb, mrb_value self);

mrb_value siren_build_polyline(mrb_state* mrb, mrb_value self);
// mrb_value siren_build_curve(mrb_state* mrb, mrb_value self);
// mrb_value siren_build_beziercurve(mrb_state* mrb, mrb_value self);
// mrb_value siren_build_nurbscurve(mrb_state* mrb, mrb_value self);

// mrb_value siren_build_wire(mrb_state* mrb, mrb_value self);

// mrb_value siren_build_rectangle(mrb_state* mrb, mrb_value self);
// mrb_value siren_build_polygon(mrb_state* mrb, mrb_value self);
// mrb_value siren_build_beziersurf(mrb_state* mrb, mrb_value self);
// mrb_value siren_build_nurbssurf(mrb_state* mrb, mrb_value self);
//
// mrb_value siren_build_shell(mrb_state* mrb, mrb_value self);
// mrb_value siren_build_solid(mrb_state* mrb, mrb_value self);

mrb_value siren_build_compound(mrb_state* mrb, mrb_value self);

#endif
