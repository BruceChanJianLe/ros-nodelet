cmake_minimum_required(VERSION 3.0.2)
project(ros-nodelet)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(catkin REQUIRED COMPONENTS
  dynamic_reconfigure
  nodelet
  nodelet_topic_tools
  roscpp
  std_msgs
)

catkin_package(
  INCLUDE_DIRS include
#  LIBRARIES ros-nodelet
#  CATKIN_DEPENDS dynamic_reconfigure nodelet nodelet_topic_tools roscpp std_msgs
#  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)