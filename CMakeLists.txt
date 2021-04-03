cmake_minimum_required(VERSION 2.8)

project(gameoflife)

set( CMAKE_BUILD_TYPE Debug)

set(CMAKE_C_FLAGS "-std=c99 -fdump-rtl-expand")
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})


add_executable(gol main.c  animation.c graphics.c input.c  )



target_link_libraries(gol ${SDL2_LIBRARIES})
