cmake_minimum_required(VERSION 3.1.3)

project(editor)

set(CMAKE_CXX_COMPILER clang++)
set(CMAKE_C_COMPILER clang)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/modules")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-long-long -pedantic -std=c++0x")
set(CMAKE_AUTOMOC ON)
set(CMAKE_BUILD_TYPE Debug)

find_package(Qt5Widgets REQUIRED)
find_package(Qt5Quick REQUIRED)
find_package(Boost REQUIRED)
find_package(ZMQ REQUIRED)
find_package(ZMQ_PP REQUIRED)
find_package(Protobuf REQUIRED)

include_directories(${ZMQ_PP_INCLUDE_DIRS})
include_directories(${PROTOBUF_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${ZMQ_INCLUDE_DIRS})
include_directories(include)
include_directories(src)

set(PROTO_SOURCES
  proto/Graph.proto
)

set(SOURCES
  src/main.cpp
  src/Workspace.cpp
  src/WorkspaceGraph.cpp
  src/Node.cpp
  src/MoveCommand.cpp
  src/ConnectCommand.cpp
  src/Connection.cpp
  src/Pin.cpp
  src/LiveReload.cpp
  src/Console.cpp

  include/Node.h
  include/Workspace.h
  include/Connection.h
  include/Pin.h
  include/LiveReload.h
  include/Console.h
)

protobuf_generate_cpp(PROTO_SRCS PROTO_HDRS ${PROTO_SOURCES})

add_executable(${PROJECT_NAME} WIN32
    ${SOURCES}
    ${PROTO_SRCS} ${PROTO_HDRS} ${PROTO_SOURCES}
)

target_link_libraries(${PROJECT_NAME}
    Qt5::Widgets Qt5::Quick
    ${Boost_LIBRARIES}
    ${ZMQ_LIBRARIES}
    ${ZMQ_PP_LIBRARIES}
    ${PROTOBUF_LIBRARY}
)
