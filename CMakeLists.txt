cmake_minimum_required(VERSION 3.25)
project(STUDY)

set(CMAKE_CXX_STANDARD 17)

# 设置可执行文件输出目录为 bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

file(GLOB SOURCES "*.cpp")

file(GLOB HEADER "include/*")

add_executable(STUDY ${SOURCES} ${HEADER})
