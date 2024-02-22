cmake_minimum_required(VERSION 3.5)
project(inav-fc)

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(std_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(mavros_msgs REQUIRED)
find_package(class_loader REQUIRED)
find_package(tf2_ros REQUIRED)
find_package(rosidl_default_generators REQUIRED)

# Include directories
include_directories(include)

# Define message and service files
set(msg_files
    "msg/MSPRaw.msg"
)
set(srv_files
    "srv/ReceiveMSPRaw.srv"
    "srv/SendMSPRaw.srv"
)

# Generate messages and services
rosidl_generate_interfaces(${PROJECT_NAME}
  ${msg_files}
  ${srv_files}
  DEPENDENCIES sensor_msgs std_msgs geometry_msgs mavros_msgs
)

# Build the executable
add_executable(main src/main.cpp)
ament_target_dependencies(main
  rclcpp
  sensor_msgs
  std_msgs
  geometry_msgs
  mavros_msgs
  class_loader
  tf2_ros
)
target_include_directories(main PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>
)

# Install targets
install(TARGETS
  main
  DESTINATION lib/${PROJECT_NAME}
)

# Install directories
install(DIRECTORY
  include/
  DESTINATION include
)

# Install messages and services
rosidl_target_interfaces(main
  ${PROJECT_NAME} "rosidl_typesupport_cpp")

ament_package()
