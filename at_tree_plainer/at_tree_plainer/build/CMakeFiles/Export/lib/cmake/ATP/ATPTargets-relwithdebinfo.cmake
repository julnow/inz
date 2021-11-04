#----------------------------------------------------------------
# Generated CMake target import file for configuration "RELWITHDEBINFO".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "ATP" for configuration "RELWITHDEBINFO"
set_property(TARGET ATP APPEND PROPERTY IMPORTED_CONFIGURATIONS RELWITHDEBINFO)
set_target_properties(ATP PROPERTIES
  IMPORTED_LOCATION_RELWITHDEBINFO "${_IMPORT_PREFIX}/lib/libATP.dylib"
  IMPORTED_SONAME_RELWITHDEBINFO "@rpath/libATP.dylib"
  )

list(APPEND _IMPORT_CHECK_TARGETS ATP )
list(APPEND _IMPORT_CHECK_FILES_FOR_ATP "${_IMPORT_PREFIX}/lib/libATP.dylib" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
