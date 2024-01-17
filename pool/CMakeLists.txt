cmake_minimum_required(VERSION 3.1)
project(pool)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(pool main.cc)

target_link_libraries(pool -pthread)
