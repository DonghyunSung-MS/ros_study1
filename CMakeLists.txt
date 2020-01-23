cmake_minimum_required(VERSION 2.8.3)
project(ros_study1)

## dependent package setting
find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  message_generation
)

## Generate services in the 'srv' folder
add_service_files(
  FILES
  Average.srv
)
## Generate added messages and services with any dependencies listed here

generate_messages(
  DEPENDENCIES
  std_msgs
)

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)


## add cpp node

add_executable(subscriber_cpp src/subscriber_cpp.cpp)
add_executable(publisher_cpp src/publisher_cpp.cpp)

## dependency setting

add_dependencies(publisher_cpp
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS})
add_dependencies(subscriber_cpp
  ${${PROJECT_NAME}_EXPORTED_TARGETS}
  ${catkin_EXPORTED_TARGETS})

target_link_libraries(publisher_cpp
  ${catkin_LIBRARIES})
target_link_libraries(subscriber_cpp
  ${catkin_LIBRARIES})
