#ifndef _BUILD_H_
#define _BUILD_H_

#include "siren.h"
#include "vec.h"
#include "shape.h"

#include <BRep_Builder.hxx>
#include <BRepBuilderAPI.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepBuilderAPI_MakePolygon.hxx>

#include <GeomAPI_Interpolate.hxx> // curve
#include <TColgp_Array1OfVec.hxx>
#include <TColgp_HArray1OfPnt.hxx>
#include <TColStd_HArray1OfBoolean.hxx>

#include <gp_Ax3.hxx> // plane
#include <gp_Pln.hxx>

#include <ShapeFix_Wire.hxx> // wire
#include <TopExp_Explorer.hxx>
#include <ShapeExtend_WireData.hxx>
#include <BRepBuilderAPI_MakeWire.hxx>
#include <ShapeFix_ShapeTolerance.hxx>

// copy
#include <BRepBuilderAPI_Copy.hxx>

bool siren_build_install(mrb_state* mrb, struct RClass* rclass);

mrb_value siren_build_copy     (mrb_state* mrb, mrb_value self);

mrb_value siren_build_vertex   (mrb_state* mrb, mrb_value self);
mrb_value siren_build_line     (mrb_state* mrb, mrb_value self);
mrb_value siren_build_polyline (mrb_state* mrb, mrb_value self);
mrb_value siren_build_curve    (mrb_state* mrb, mrb_value self);
mrb_value siren_build_wire     (mrb_state* mrb, mrb_value self);
mrb_value siren_build_plane    (mrb_state* mrb, mrb_value self);
mrb_value siren_build_polygon  (mrb_state* mrb, mrb_value self);

// mrb_value siren_build_beziercurve(mrb_state* mrb, mrb_value self);
// mrb_value siren_build_nurbscurve(mrb_state* mrb, mrb_value self);
// mrb_value siren_build_rectangle(mrb_state* mrb, mrb_value self);
// mrb_value siren_build_beziersurf(mrb_state* mrb, mrb_value self);
// mrb_value siren_build_nurbssurf(mrb_state* mrb, mrb_value self);
// mrb_value siren_build_shell(mrb_state* mrb, mrb_value self);
// mrb_value siren_build_solid(mrb_state* mrb, mrb_value self);

mrb_value siren_build_compound(mrb_state* mrb, mrb_value self);

#endif
