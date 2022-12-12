cmake_minimum_required(VERSION 2.8)
project(PongRaylib)

set(my_includes "./includes/actors.h" "./includes/score.h")
set(my_cpp "./src/main.cpp" "./src/actors.cpp" "./src/score.cpp")

add_definitions("-std=c++11")

include_directories("./includes")
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_executable(main ${my_includes} ${my_cpp})
target_link_libraries(main ${CONAN_LIBS})
