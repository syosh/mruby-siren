##
#
# Compatibility class
#
#

{
  BRepIO: {
    save: "save_brep",
    load: "load_brep",
    dump: "dump",
  },
  IGES: {
    save: "save_iges",
    load: "load_iges"
  },
  STL: {
    save: "save_stl",
    load: "load_stl"
  },
  STEP: {
    save: "save_step",
    load: "load_step"
  },
  Prim: {
    box:        "box",
    box2p:      "box2p",
    boxax:      "boxax",
    sphere:     "sphere",
    cylinder:   "cylinder",
    cone:       "cone",
    torus:      "torus",
    halfspace:  "halfspace",
    prism:      "prism",
    revol:      "revol",
    revolution: "revolution",
    wedge:      "wedge",
  },
  Build: {
    copy:       "copy",
    vertex:     "vertex",
    line:       "line",
    infline:    "infline",
    polyline:   "polyline",
    curve:      "curve",
    wire:       "wire",
    arc:        "arc",
    arc3p:      "arc3p",
    circle:     "circle",
    circle3p:   "circle3p",
    plane:      "plane",
    face:       "face",
    infplane:   "infplane",
    polygon:    "polygon",
    nurbscurve: "nurbscurve",
    beziersurf: "beziersurf",
    nurbssurf:  "nurbssurf",
    sewing:     "sewing",
    solid:      "solid",
    compound:   "compound",
  },
  Offset: {
    sweep_vec:       "sweep_vec",
    sweep_path:      "sweep_path",
    loft:            "loft",
    offset_geomsurf: "offset_geomsurf",
    offset:          "offset",
    offset_shape:    "offset_shape",
    pipe:            "pipe",
  },
}.each do |mod, ms|
  newmod = self.class.const_set mod, Module.new
  ms.each do |from, dest|
    newmod.define_singleton_method(from) do |*args|
      Siren.warn "#{mod}.#{from} is an abolished method. Use Siren.#{dest} instead."
      Siren.send(dest, *args)
    end
  end
end

module ShapeType
  COMPOUND  = 0
  COMPSOLID = 1
  SOLID     = 2
  SHELL     = 3
  FACE      = 4
  WIRE      = 5
  EDGE      = 6
  VERTEX    = 7
  SHAPE     = 8
end

