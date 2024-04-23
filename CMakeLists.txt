cmake_minimum_required(VERSION 3.29)
project(CyberNet; LANGUAGES CXX)

set(Server; "${CMAKE_SOURCE_DIR}/server")
set(Client; "${CMAKE_SOURCE_DIR}/client")
set(Asio; "${CMAKE_SOURCE_DIR}/asio")
set(Inner_asio; "${CMAKE_SOURCE_DIR}/asio/include/asio")

set(CXX_STANDARD; 20)

add_executable(${PROJECT_NAME}; main.cpp; ${Server}/commands.cpp)

target_include_directories(${PROJECT_NAME}; PRIVATE
    # Server
    Server;
    # Client
    Client;

    # Library
    Asio;
    Inner_asio
)