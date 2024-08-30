cmake_minimum_required(VERSION 3.30)
project(tests)

set(Server_tests "stests")
set(Client_tests "ctests")
set(tests_dir ${CMAKE_SOURCE_DIR}/tests/)
add_subdirectory(GoogleTest)

add_executable(${Server_tests} ${tests_dir}/server_tests.cpp)
add_executable(${Client_tests} ${tests_dir}/client_test.cpp)

target_link_libraries(${Server_tests}  gtest gtest_main)
target_link_libraries(${Client_tests}  gtest gtest_main) 