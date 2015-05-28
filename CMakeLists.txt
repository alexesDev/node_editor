cmake_minimum_required(VERSION 3.1.3)

project(editor)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/modules")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic -std=c++0x")
set(CMAKE_AUTOMOC ON)
set(CMAKE_BUILD_TYPE Debug)

find_package(Qt5Widgets)
find_package(Qt5Quick)

include_directories(include)
include_directories(src)

set(SOURCES
  src/main.cpp
  src/Workspace.cpp
  src/WorkspaceGraph.cpp
  src/Node.cpp
  src/MoveCommand.cpp
  src/ConnectCommand.cpp
  src/Connection.cpp
  src/Pin.cpp

  include/Node.h
  include/Workspace.h
  include/Connection.h
  include/Pin.h
)

add_executable(${PROJECT_NAME} WIN32 ${SOURCES})
target_link_libraries(${PROJECT_NAME} Qt5::Widgets Qt5::Quick)
