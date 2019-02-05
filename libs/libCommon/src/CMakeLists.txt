set(LIBCOMMON_SRC_PATH "${PROJECT_SOURCE_DIR}/src/libCommon")
file(GLOB_RECURSE LIBCOMMON_SRC_FILES "*.cpp" )
file(GLOB_RECURSE LIBCOMMON_HEADERS_FILES "*.hpp" "*.h" )

# external dependency
SET( Boost_USE_STATIC_LIBS ON )
FIND_PACKAGE( Boost COMPONENTS system regex log log_setup thread atomic filesystem REQUIRED )

# Create 'libCommon' static lib
add_library( libCommon-static STATIC ${LIBCOMMON_SRC_FILES} ${LIBCOMMON_HEADERS_FILES} )
set_target_properties( libCommon-static PROPERTIES LINKER_LANGUAGE CXX )
set_target_properties( libCommon-static PROPERTIES OUTPUT_NAME libCommon )
target_include_directories( libCommon-static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${Boost_INCLUDE_DIRS} )
if( MSVC )
    target_link_libraries( libCommon-static PUBLIC "dbghelp.lib" "Psapi.lib" ${Boost_LIBRARIES} )
else()
    target_link_libraries( libCommon-static PUBLIC ${Boost_LIBRARIES} )
endif()


### Install libCommon libs and include
INSTALL(
	DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
	DESTINATION "include"
	FILES_MATCHING
	PATTERN "*.hpp"
	PATTERN "*.h"
	PATTERN "*.tcc"
)

INSTALL(TARGETS libCommon-static DESTINATION lib/ OPTIONAL)
