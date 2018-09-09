file(GLOB_RECURSE SRC_FILES_GLOB "*.cpp" "*.hpp" "*.h" )

add_executable( problem001 ${SRC_FILES_GLOB} )
set_target_properties( problem001 PROPERTIES LINKER_LANGUAGE CXX )
set_target_properties( problem001 PROPERTIES OUTPUT_NAME problem001 )


