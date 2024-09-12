cmake_minimum_required(VERSION 3.20)
project(tests)
enable_testing()

set(Server_tests "tserver")
set(Client_tests "tclient")
set(tests_dir ${CMAKE_SOURCE_DIR}/tests/)
add_subdirectory(GoogleTest)

include_directories(

    # Library
    ${CMAKE_SOURCE_DIR}/asio/asio/include
    ${CMAKE_SOURCE_DIR}/asio/asio/include/asio/detail
    ${CMAKE_SOURCE_DIR}/asio/asio/include/asio
    ${Boost_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/src/client
)

add_executable(${Server_tests}
    ${CMAKE_SOURCE_DIR}/tests/server_tests.cpp
    ${CMAKE_SOURCE_DIR}/src/server/server.cpp
    ${CMAKE_SOURCE_DIR}/src/server/session.cpp
    ${CMAKE_SOURCE_DIR}/src/server/title.cpp
    ${CMAKE_SOURCE_DIR}/src/server/commands.cpp
    ${CMAKE_SOURCE_DIR}/src/internet_computer.cpp

)

add_executable(${Client_tests}
    ${tests_dir}/client_test.cpp
    ${tests_dir}/client_t.cpp
    ${CMAKE_SOURCE_DIR}/src/client/client.cpp
    ${CMAKE_SOURCE_DIR}/src/internet_computer.cpp
    )

if(${CMAKE_SYSTEM_NAME} STREQUAL "Darwin" OR ${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
    target_link_libraries(${Server_tests}  gtest gtest_main)
    target_link_libraries(${Client_tests}  gtest gtest_main)

elseif(${CMAKE_SYSTEM_NAME} STREQUAL "Windows")
    target_link_libraries(${Server_tests}  gtest gtest_main ws2_32 mswsock)
    target_link_libraries(${Client_tests}  gtest gtest_main ws2_32 mswsock)

else()
    message("Error. Failed to identify system.")
    return(-1)
endif()


add_test(NAME Server_test COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${Server_tests})
add_test(NAME Client_test COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${Client_tests})
