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

# example publisher
add_executable(example_publisher
  src/publisher_node.cpp
  src/publisher.cpp
)
target_link_libraries(example_publisher ${catkin_LIBRARIES})

# Add example_sub_pub lib
add_library(
  example_sub_pub
  src/subscriber_publisher.cpp
  src/subscriber_publisher2.cpp
)
add_dependencies(example_sub_pub ${catkin_EXPORTED_TARGETS})
target_link_libraries(example_sub_pub ${catkin_LIBRARIES})

# Add exmaple_sub_pub nodelet executable
add_executable(nodelet_sub_pub_node src/subscriber_publisher_node.cpp)
target_link_libraries(nodelet_sub_pub_node ${catkin_LIBRARIES})

# # Add example_sub_pub2 lib
# add_library(
#   example_sub_pub2
#   src/subscriber_publisher2.cpp
# )
# add_dependencies(example_sub_pub2 ${catkin_EXPORTED_TARGETS})
# target_link_libraries(example_sub_pub2 ${catkin_LIBRARIES})

# Add exmaple_sub_pub nodelet executable
add_executable(nodelet_sub_pub_node2 src/subscriber_publisher_node.cpp)
target_link_libraries(nodelet_sub_pub_node2 ${catkin_LIBRARIES})