cmake_minimum_required(VERSION 3.8)
project(projectEuler)

set(ENABLE_PROB_001 TRUE  CACHE BOOL "Multiples of 3 and 5")
set(ENABLE_PROB_004 TRUE CACHE BOOL "Largest palindrome product")
set(ENABLE_PROB_015 TRUE CACHE BOOL "Lattice path problem")


SET(CMAKE_MODULE_PATH "${CMAKE_CURRENT_PATH}/cmake")

if(WIN32) # Windows
    add_definitions(-DUNICODE -D_UNICODE)
    set(TARGET_ARCHITECTURE "x64")
#    set(TARGET_ARCHITECTURE "x86")
endif()

#add_subdirectory(libs)
add_subdirectory(problems)