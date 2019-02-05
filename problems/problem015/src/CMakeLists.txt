file(GLOB_RECURSE SRC_FILES_GLOB "*.cpp" "*.hpp" "*.h" )

SET( Boost_USE_STATIC_LIBS ON )
#FIND_PACKAGE(Boost COMPONENTS system log filesystem REQUIRED)

add_executable( problem015 ${SRC_FILES_GLOB} )
set_target_properties( problem015 PROPERTIES LINKER_LANGUAGE CXX )
set_target_properties( problem015 PROPERTIES OUTPUT_NAME problem015 )


#target_include_directories( problem015 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${Boost_INCLUDE_DIRS} libCommon-static )
#target_link_libraries( problem015 PUBLIC ${Boost_LIBRARIES} libCommon-static)