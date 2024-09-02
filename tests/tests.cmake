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
    ${CMAKE_SOURCE_DIR}../src/client/client.cpp
)

add_executable(${Server_tests} ${tests_dir}/server_tests.cpp)

add_executable(${Client_tests} ${tests_dir}/client_test.cpp
    ${CMAKE_SOURCE_DIR}../src/client/client.cpp
    ${CMAKE_SOURCE_DIR}../src/client/title.cpp
    )

target_link_libraries(${Server_tests}  gtest gtest_main ws2_32 mswsock)
target_link_libraries(${Client_tests}  gtest gtest_main ws2_32 mswsock) 

add_test(NAME Server_test COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${Server_tests})
add_test(NAME Client_test COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${Client_tests})
