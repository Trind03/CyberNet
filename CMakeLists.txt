cmake_minimum_required(VERSION 3.20)
project(CyberNet)

set(server "${CMAKE_SOURCE_DIR}/server")
include_directories(
    # Server
    ${CMAKE_SOURCE_DIR}/server
    ${CMAKE_SOURCE_DIR}/server/includes

    # Library
    ${CMAKE_SOURCE_DIR}/Simple-Web-Server
)

add_executable(main ${server}/main.cpp)