cmake_minimum_required(VERSION 3.29)
project(CyberNet LANGUAGES CXX)

set(CXX_STANDARD 20)

# Executable names
set(Client_name "client")
set(Server_name "server")

# File path init
set(Server "${CMAKE_SOURCE_DIR}/server")
set(Client "${CMAKE_SOURCE_DIR}/client")
set(Asio "${CMAKE_SOURCE_DIR}/asio")
set(Inner_asio "${CMAKE_SOURCE_DIR}/asio/include/asio")


include_directories(
    # Server
    ${Server}

    # Client
    ${Client}

    # Library
    ${Asio}
    ${Inner_asio}
)


add_executable(${Server_name} ${Server}/main.cpp ${Server}/commands.cpp ${Server}/server.cpp)
add_executable(${Client_name} ${Client}/main.cpp ${Client}/Net_conn.cpp)