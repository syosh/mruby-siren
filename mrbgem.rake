##
# mruby-siren rake file
#

MRuby::Gem::Specification.new('mruby-siren') do |spec|

  # General spec
  spec.author  = 'dyama'
  spec.summary = 'Lightweight 3D operation environment.'
  spec.license = 'MIT license'

  # siren configuration
  spec.add_dependency 'mruby-io'
  siren_incpath = File.expand_path(File.dirname(__FILE__)) + '/inc'

  # Open CASCADE Technology configuration
  # Check http://dev.opencascade.org/doc/refman/html/index.html
  thirdparty_libs = []
  occt_libpaths   = []
  occt_incpaths   = []

  if occt_libpaths.size == 0 and occt_incpaths.size == 0
    os = RbConfig::CONFIG['host_os'].downcase
    case os
    when /linux|solaris|bsd/
      occt_libpaths = [ '/opt/occ/700/lin64/gcc/lib' ]
      occt_incpaths = [ '/opt/occ/700/inc' ]
    when /darwin|mac os/
      occt_libpaths = [ '/usr/local/opt/opencascade/lib' ]
      occt_incpaths = [ '/usr/local/opt/opencascade/include/opencascade' ]
    when /mswin|mingw/
      occt_libpaths = [ '\occ\700\mingw32\gcc\lib' ]
      occt_incpaths = [ '\occ\700\inc' ]
      spec.cxx.flags << '-D_USE_MATH_DEFINES -D__NO_INLINE__'
    end
  end

  occt_libs = [
    # Foundation classes
    'TKernel', 'TKMath',
    # Modeling data
    'TKG2d', 'TKG3d', 'TKGeomBase', 'TKBRep',
    # Modeling algorithms
    'TKGeomAlgo', 'TKTopAlgo', 'TKBO', 'TKPrim',
    'TKShHealing', 'TKHLR', 'TKMesh', 'TKBool',
    'TKXMesh', 'TKFeat', 'TKFillet', 'TKOffset',
    # Data excange
    'TKXSBase', 'TKSTL', 'TKIGES', 'TKSTEP',
    'TKSTEP209', 'TKSTEPAttr', 'TKSTEPBase',
  ]

  # Linker option
  spec.linker.library_paths << occt_libpaths
  spec.linker.libraries << occt_libs << thirdparty_libs

  # Compiler option
  spec.cxx.flags << occt_incpaths.map{|n| "-I\"#{n}\"" } << " -I\"#{siren_incpath}\"" <<
    "-Wno-unused-function -Wno-unused-variable -Wno-unknown-pragmas -std=c++11"

end

