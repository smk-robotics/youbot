cmake_minimum_required(VERSION 3.10.0)
project(damir VERSION 0.0.1)

find_package(catkin REQUIRED COMPONENTS
  actionlib
  roscpp
  move_base_msgs
)

catkin_package()

add_executable(navigation_node
  src/navigation/navigation_node.cpp
)

target_link_libraries(navigation_node PRIVATE
  ${catkin_LIBRARIES}
)

target_include_directories(navigation_node PRIVATE
  ${catkin_INCLUDE_DIRS}
)