cmake_minimum_required(VERSION 3.29)
project(CyberNet LANGUAGES CXX)

add_definitions(-D Windows)
set(CXX_STANDARD 20)

# Executable names
set(Client_name "client")
set(Server_name "server")

# File path init
set(Server "${CMAKE_SOURCE_DIR}/server")
set(Client "${CMAKE_SOURCE_DIR}/client")



include_directories(
    # Server
    ${Server}

    # Client
    ${Client}

    # Library
    ${CMAKE_SOURCE_DIR}/asio/asio/include
    ${CMAKE_SOURCE_DIR}/asio/asio/src
)


add_executable(${Server_name} ${Server}/main.cpp ${Server}/commands.cpp ${Server}/server.cpp)
#add_executable(${Client_name} ${Client}/main.cpp ${Client}/Net_conn.cpp)
#if(DEFINED Windows)
target_link_libraries(${Server_name} ws2_32 mswsock)
add_definitions(-D_WIN32_WINNT=0x0601)
#endif()