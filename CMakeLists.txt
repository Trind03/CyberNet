cmake_minimum_required(VERSION 3.0)
project(CyberNet)

set(server "${CMAKE_SOURCE_DIR}/server")

include_directories(
    # Server
    ${CMAKE_SOURCE_DIR}/server
    # Client
    ${CMAKE_SOURCE_DIR}/client

    # Library
    #${CMAKE_SOURCE_DIR}/Simple-Web-Server
)

add_executable(main 
    main.cpp
    
    )