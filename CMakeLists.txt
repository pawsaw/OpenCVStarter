cmake_minimum_required(VERSION 3.19.0)
project(OpenCVStarter VERSION 0.1.0)

include(CTest)
enable_testing()

# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
find_package(OpenCV REQUIRED)

# If the package has been found, several variables will
# be set, you can find the full list with descriptions
# in the OpenCVConfig.cmake file.
# Print some message showing some of them
message(STATUS "OpenCV library status:")
message(STATUS "    config: ${OpenCV_DIR}")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

add_executable(OpenCVStarter main.cpp)

target_include_directories(OpenCVStarter PUBLIC "${OpenCV_INCLUDE_DIRS}")
target_include_directories(OpenCVStarter PUBLIC "${PROJECT_BINARY_DIR}")

# Link your application with OpenCV libraries
target_link_libraries(OpenCVStarter PRIVATE ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
