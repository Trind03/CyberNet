cmake_minimum_required(VERSION 3.29)
project(CyberNet LANGUAGES CXX)

set(Winx64 TRUE)
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

# Platform dependant code

add_executable(${Server_name} ${Server}/main.cpp ${Server}/commands.cpp ${Server}/server.cpp)
#add_executable(${Client_name} ${Client}/main.cpp ${Client}/Net_conn.cpp)

if(Winx64)
target_link_libraries(${Server_name} ws2_32 mswsock)
#target_link_libraries(${Client_name} ws2_32 mswsock)
add_definitions(-D_WIN32_WINNT=0x0601)
endif()