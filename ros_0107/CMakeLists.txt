cmake_minimum_required(VERSION 2.8.3)
project(ros_0107)

find_package(catkin REQUIRED)

find_package(catkin REQUIRED COMPONENTS
  message_generation
  roscpp
)
add_message_files(FILES
  ros_0107_msg.msg
)


generate_messages(DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS
  message_runtime
)

include_directories(
  include ${catkin_INCLUDE_DIRS}
)



add_executable(ros_0107_pub
  src/ros_0107_pub.cpp
)
add_dependencies(ros_0107_pub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ros_0107_pub
  ${catkin_LIBRARIES}
)

add_executable(ros_0107_sub
  src/ros_0107_sub.cpp
)
add_dependencies(ros_0107_sub ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})
target_link_libraries(ros_0107_sub
  ${catkin_LIBRARIES}
)