#copied cmakeLists
cmake_minimum_required(VERSION 3.2)
project(BounceBack)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

# Set default build type explicitly to Release
if (NOT CMAKE_BUILD_TYPE)
  set (CMAKE_BUILD_TYPE "Release" CACHE STRING "Choose the type of build type." FORCE)
endif (NOT CMAKE_BUILD_TYPE)

set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules/)

if(NOT SFML_ROOT)
  set(SFML_ROOT CACHE "" FORCE)
endif()

# Find SFML
#set(SFML_DYNAMIC_LIBRARIES TRUE)
find_package(SFML REQUIRED COMPONENTS audio graphics window system)

if(NOT SFML_FOUND)
  message(FATAL_ERROR "SFML couldn't be located!")
endif()

include_directories(${SFML_INCLUDE_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)

set(SOURCE_FILES
  src/main.cpp
  src/Game.cpp
  src/Game.h
  src/GUI.cpp
  src/GUI.h
  src/Menu.cpp
  src/Menu.h
  src/ball.cpp
  src/ball.h
  src/paddle1.cpp
  src/paddle1.h
  src/Player/Paddle.cpp
  src/Player/Paddle.h
  src/Player/PaddleController.cpp
  src/Player/PaddleController.h
  src/StateManager.cpp
  src/StateManager.h
  src/Globals.h
)

#set(HEADER_FILES
#  src/*.hpp
#  src/*.h
#)

add_executable(BounceBack ${SOURCE_FILES})

target_link_libraries(BounceBack ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})

# Install executable
install(TARGETS BounceBack
  RUNTIME DESTINATION .
)

# Install game data
install(DIRECTORY bin/res
  DESTINATION .
) 	