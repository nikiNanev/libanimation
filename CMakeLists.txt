cmake_minimum_required(VERSION 3.25)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

project(anim)

include_directories("${CMAKE_SOURCE_DIR}/include/*")

add_executable(${PROJECT_NAME} src/main.c)

