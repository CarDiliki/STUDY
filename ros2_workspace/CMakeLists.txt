cmake_minimum_required(VERSION 3.16.3)
project(ros2_workspace)

set(CMAKE_CXX_STANDARD 17)

# 添加编译选项
add_compile_options(-Wall -Wextra -pedantic -Werror)

# 设置外部库的路径
set(ROS2_INC_PATH /opt/ros/galactic/include)


# REQUIRED 它指示 find_package 在查找指定的包时，如果找不到这个包，就停止配置并报错
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(Protobuf REQUIRED)
include_directories(${PROTOBUF_INCLUDE_DIRS} ${ROS2_INC_PATH})

file(GLOB_RECURSE PROTO_SRCS "${CMAKE_CURRENT_SOURCE_DIR}/common/proto/*.pb.cc")

add_library(your_message_lib ${PROTO_SRCS})

add_executable(my_publisher src/my_publisher_pkg/my_publisher_node.cpp)
ament_target_dependencies(my_publisher rclcpp std_msgs)

add_executable(my_subscriber src/my_subscriber_pkg/my_subscriber_node.cpp)
ament_target_dependencies(my_subscriber rclcpp std_msgs)