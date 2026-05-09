cmake_minimum_required(VERSION 3.10)
project(client-server)

set(CMAKE_CXX_STANDARD 17)

find_package(Boost REQUIRED)

add_executable(myserver server.cpp)
target_include_directories(myserver PRIVATE ${Boost_INCLUDE_DIRS})

