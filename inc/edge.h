#ifndef _SINGLETON_EDGE_H_
#define _SINGLETON_EDGE_H_

#include "siren.h"
#include "curve.h"
#include "shape.h"

#include <TopoDS.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Wire.hxx>

#include <TopExp_Explorer.hxx>
#include <BRepAdaptor_Curve.hxx>

// to_pts
#include <BRepAdaptor_Curve.hxx>
#include <GCPnts_UniformDeflection.hxx>

// param
#include <ShapeAnalysis_Curve.hxx>
#include <BRepAdaptor_Curve.hxx>

// nurbs def
#include <Geom_Curve.hxx>
#include <BRep_Tool.hxx>
#include <Geom_TrimmedCurve.hxx>
#include <Geom_BSplineCurve.hxx>

#include <BRepExtrema_ExtCC.hxx>

void siren_edge_install(mrb_state* mrb, RObject* o);
mrb_value siren_edge_sp(mrb_state* mrb, mrb_value self);
mrb_value siren_edge_tp(mrb_state* mrb, mrb_value self);
mrb_value siren_edge_to_pts(mrb_state* mrb, mrb_value self);
mrb_value siren_edge_param(mrb_state* mrb, mrb_value self);
mrb_value siren_edge_to_xyz(mrb_state* mrb, mrb_value self);
mrb_value siren_edge_curvature(mrb_state* mrb, mrb_value self);
mrb_value siren_edge_tangent(mrb_state* mrb, mrb_value self);

mrb_value siren_edge_nurbs_def(mrb_state* mrb, mrb_value self);

mrb_value siren_edge_first(mrb_state* mrb, mrb_value self);
mrb_value siren_edge_last(mrb_state* mrb, mrb_value self);
mrb_value siren_edge_params(mrb_state* mrb, mrb_value self);
mrb_value siren_edge_curve(mrb_state* mrb, mrb_value self);

mrb_value siren_edge_split(mrb_state* mrb, mrb_value self);
mrb_value siren_edge_trim(mrb_state* mrb, mrb_value self);
mrb_value siren_edge_extrema(mrb_state* mrb, mrb_value self);

mrb_value siren_edge_length(mrb_state* mrb, mrb_value self);

#endif
