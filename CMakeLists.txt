cmake_minimum_required(VERSION 3.30)
project(CyberNet LANGUAGES CXX)

# Defining global source macros for build
add_compile_definitions(server_ip="0.0.0.0")
add_compile_definitions(client_connect="10.4.5.209")
add_compile_definitions(Active_Port=5554)

add_compile_definitions(_Debug_=true)

set(${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR}/build)
file(COPY ${CMAKE_SOURCE_DIR}/title.dat DESTINATION ${CMAKE_BINARY_DIR})
#include(${CMAKE_SOURCE_DIR}/tests/tests.cmake)


# Executable names
set(Client "client")
set(Server "server")

# Settings init
set(Standard "c++20")
set(CMAKE_CXX_EXTENSIONS OFF)

# File path init
set(Server_dir "${CMAKE_SOURCE_DIR}/src/server")
set(Client_dir "${CMAKE_SOURCE_DIR}/src/client")
set(Root_src "${CMAKE_SOURCE_DIR}/src")
set(Lib "${CMAKE_SOURCE_DIR}/src/lib")

set(Clientlib "${CMAKE_SOURCE_DIR}/src/Serverlib")
set(Serverlib "${CMAKE_SOURCE_DIR}/src/Clientlib")


include_directories(
    # Server
    ${Server_dir}

    # Client
    ${Client_dir}

    
    # Source dir

    ${Root_src}
    
    # Library
    ${CMAKE_SOURCE_DIR}/asio/asio/include
    ${CMAKE_SOURCE_DIR}/asio/asio/include/asio/detail
    ${CMAKE_SOURCE_DIR}/asio/asio/include/asio
    ${Boost_INCLUDE_DIRS}

)

# Client
    add_library(C_client SHARED ${Client_dir}/client.cpp)
    add_library(C_commands SHARED ${Client_dir}/command.cpp)
    add_library(C_title SHARED ${Client_dir}/title.cpp)
    add_library(C_Internet_computer SHARED ${CMAKE_SOURCE_DIR}/src/Internet_computer.cpp)

# Server
    add_library(S_commands SHARED ${Server_dir}/commands.cpp)
    add_library(S_server SHARED ${Server_dir}/server.cpp)
    add_library(S_session SHARED ${Server_dir}/session.cpp)
    add_library(S_title SHARED ${Server_dir}/title.cpp)
    add_library(S_Internet_computer SHARED ${CMAKE_SOURCE_DIR}/src/Internet_computer.cpp)

# Platform dependant code
if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    message("-- System identyfied as: Windows")
    set(CXX_STANDARD Standard)

    add_executable(${Server} ${Server_dir}/main.cpp)

    target_link_libraries(${Server} PRIVATE
        S_commands
        S_server
        S_session
        S_title
        S_Internet_computer
        ws2_32 mswsock
    )

    add_executable(${Client} ${Client_dir}/main.cpp)
    target_link_libraries(${Client} PRIVATE
        C_commands
        C_title
        C_Internet_computer
        C_client
        ws2_32 mswsock
        )

    add_definitions(-D_WIN32_WINNT=0x0601)

    return()
elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    message("-- System identyfied as: MacOS")
    find_package(Boost REQUIRED)
    add_compile_options(-std=${Standard})
    set(CMAKE_CXX_COMPILER "clang++")

    add_executable(${Server} ${server_build_list})
    add_executable(${Client} ${client_build_list})
    return()

elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    message("-- System identyfied as: Linux")
    find_package(Boost REQUIRED)
    set(CMAKE_CXX_COMPILER "g++")
    add_compile_options(-std=${Standard})
    
    add_executable(${Server} ${server_build_list})
    add_executable(${Client} ${client_build_list})
    return()

else()
    message("Error. Failed to identify system.")
    return(-1)
    
endif()