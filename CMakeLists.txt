cmake_minimum_required(VERSION 3.0)
project(CyberNet)

set(server "${CMAKE_SOURCE_DIR}/server")


add_executable(main main.cpp)

target_include_directories(main PUBLIC
    # Server
    ${CMAKE_SOURCE_DIR}/server
    # Client
    ${CMAKE_SOURCE_DIR}/client

    # Library
    ${CMAKE_SOURCE_DIR}/asio
)