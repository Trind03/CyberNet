cmake_minimum_required(VERSION 3.29)
project(CyberNet LANGUAGES CXX)

set(server "${CMAKE_SOURCE_DIR}/server")

set(CXX_STANDARD 20)

add_executable(main main.cpp)

target_include_directories(main PUBLIC
    # Server
    ${CMAKE_SOURCE_DIR}/server
    # Client
    ${CMAKE_SOURCE_DIR}/client

    # Library
    ${CMAKE_SOURCE_DIR}/asio
)