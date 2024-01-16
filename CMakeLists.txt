#cmake_minimum_required(VERSION 3.25)
#project(STUDY)
#
#set(CMAKE_CXX_STANDARD 11)
#
#add_executable(STUDY main.cpp "include/Valid Anagram.h" common.h include/IntersectionOfTwoArrays.h
#        include/TwoSum.h include/PalindromicSubstrings.hpp)
cmake_minimum_required(VERSION 3.27)
project(STUDY)

set(CMAKE_CXX_STANDARD 14)

include_directories(include/)

add_executable(STUDY main.cpp)

target_link_libraries(STUDY -pthread)