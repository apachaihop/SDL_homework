cmake_minimum_required(VERSION 3.19.7...3.22)

if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)
  message(FATAL_ERROR "Prevented in-tree build. Please create a build directory outside of the SDL source code and run \"cmake -S ${CMAKE_SOURCE_DIR} -B .\" from there")
endif()

project(SDL_static LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SDL_static main.cpp)

find_package(SDL3 REQUIRED)

target_link_libraries(SDL_static PRIVATE SDL3::SDL3-static)
set_property(TARGET SDL_static PROPERTY POSITION_INDEPENDENT_CODE
                                                   TRUE)
