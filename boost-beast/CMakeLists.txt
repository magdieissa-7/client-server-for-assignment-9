cmake_minimum_required(VERSION 3.10)
project(boost-beast)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED)

add_executable(mybeast beast.cpp)
target_include_directories(mybeast PRIVATE ${Boost_INCLUDE_DIRS})
