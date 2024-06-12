cmake_minimum_required(VERSION 3.29)
project(CyberNet LANGUAGES CXX)


# Executable names
set(Client_name "client")
set(Server_name "server")

# File path init
set(Server "${CMAKE_SOURCE_DIR}/server")
set(Client "${CMAKE_SOURCE_DIR}/client")

# Platform dependant code

if(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    message("-- System identyfied as: Windows")
    target_link_libraries(${Server_name} ws2_32 mswsock)
    #target_link_libraries(${Client_name} ws2_32 mswsock)
    add_definitions(-D_WIN32_WINNT=0x0601)

elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin")
    message("-- System identyfied as: MacOS")
    find_package(Boost REQUIRED)
    set(CMAKE_CXX_COMPILER "clang++")
    add_compile_options(-std=c++20)

elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    message("-- System identyfied as: Linux")
    find_package(Boost REQUIRED)
    set(CMAKE_CXX_COMPILER "g++")
    add_compile_options(-std=c++20)
else()
    message("Error. Failed to identify system.")
    return(-1)
endif()


include_directories(
    # Server
    ${Server}

    # Client
    ${Client}

    # Library
    ${CMAKE_SOURCE_DIR}/asio/asio/include
    ${CMAKE_SOURCE_DIR}/asio/asio/src
    ${CMAKE_SOURCE_DIR}/asio/asio/include/asio/detail
    ${Boost_INCLUDE_DIRS}
)

add_executable(${Server_name} ${Server}/main.cpp ${Server}/commands.cpp ${Server}/server.cpp)
#add_executable(${Client_name} ${Client}/main.cpp ${Client}/Net_conn.cpp)