cmake_minimum_required(VERSION 3.25)
project(STUDY)

set(CMAKE_CXX_STANDARD 11)

include_directories(include/ include/common/)

file(GLOB_RECURSE SRC_FILES src/*.cpp)

add_executable(STUDY ${SRC_FILES})

target_link_libraries(STUDY -pthread)