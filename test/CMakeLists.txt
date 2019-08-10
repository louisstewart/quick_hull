cmake_minimum_required(VERSION 3.13)
project(quickhull_test)
enable_testing()

set(CMAKE_CXX_STANDARD 17)

set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME ON)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(tester test_vector2d.cpp test_line2d.cpp)
target_link_libraries(tester ${Boost_LIBRARIES})