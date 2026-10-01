cmake_minimum_required(VERSION 3.25)
project(cbank C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB SOURCES CONFIGURE_DEPENDS "src/*.c")

add_executable(cbank ${SOURCES})

target_include_directories(cbank PRIVATE include)