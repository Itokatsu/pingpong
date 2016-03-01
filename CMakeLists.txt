cmake_minimum_required(VERSION 2.8.4)
project(pong)

# Compiler Options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -Wextra -std=c++11")

# Project Tree 
# | SOURCES DIRECTORY
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(SRC_EXT cpp) # SOURCES EXTENSION
# | EXECUTABLE DIRECTORY
set(EXE_NAME ${PROJECT_NAME}) #EXECUTABLE NAME
# | HEADERS DIRECTORY
include_directories(include)

# Get Sources files
file(GLOB SOURCES_FILES "${SRC_DIR}/*.${SRC_EXT}")
# specify output directories
SET(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)

# Include SDL2
include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2)
include_directories (${SDL2_INCLUDE_DIRS})

add_executable(${EXE_NAME} ${SOURCES_FILES})
target_link_libraries(${EXE_NAME} ${SDL2_LIBRARIES})

add_custom_target(run
    COMMAND ${EXE_NAME}
    DEPENDS ${EXE_NAME}
)