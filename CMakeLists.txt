cmake_minimum_required(VERSION 3.29)
project(CyberNet LANGUAGES CXX)

# Executable names
set(Client_name "client")
set(Server_name "server")

# File path init
set(Server "${CMAKE_SOURCE_DIR}/server")
set(Client "${CMAKE_SOURCE_DIR}/client")
set(Asio "${CMAKE_SOURCE_DIR}/asio")
set(Inner_asio "${CMAKE_SOURCE_DIR}/asio/include/asio")


set(CXX_STANDARD 20)

add_executable(${Server_name} ${Server}/main.cpp ${Server}/commands.cpp ${Server}/user.cpp)
add_executable(${Client_name} ${client}/main.cpp)

target_include_directories(${PROJECT_NAME} PRIVATE
    # Server
    ${Server}

    # Client
    ${Client}

    # Library
    ${Asio}
    ${Inner_asio}
)
