cmake_minimum_required(VERSION 3.0)
project(pong)

# RANDOM CMAKE OPTIONS
SET(CMAKE_COLOR_MAKEFILE ON)

# Compiler Options
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -Wall -std=c++11")

# Project Tree 
# | CMAKE MODULES DIRECTORY 
SET(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake")
# | SOURCES DIRECTORY
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)
set(SRC_EXT cpp)
# | HEADERS DIRECTORY
set(HEADER_DIR ${CMAKE_SOURCE_DIR}/include)

# Get Sources files
file(GLOB SOURCES_FILES "${SRC_DIR}/*.${SRC_EXT}")

# specify output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# specity executable name
set(EXE_NAME ${PROJECT_NAME})

# FIND SDL2 libraries
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)

# Include headers and libraries
include_directories (${HEADER_DIR} ${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR} )

# compile
add_executable(${EXE_NAME} ${SOURCES_FILES})
target_link_libraries(${EXE_NAME} ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})

# add make run target
add_custom_target(run
    COMMAND ${EXE_NAME}
    DEPENDS ${EXE_NAME}
)