cmake_minimum_required(VERSION 3.0)
project(CyberNet)

set(server "${CMAKE_SOURCE_DIR}/server")

#add_subdirectory(asio)

include_directories(
    # Server
    ${CMAKE_SOURCE_DIR}/server
    # Client
    ${CMAKE_SOURCE_DIR}/client

    # Library
    ${CMAKE_SOURCE_DIR}/asio
)

add_executable(main main.cpp)