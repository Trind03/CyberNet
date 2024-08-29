cmake_minimum_required(VERSION 3.30)
project(tests)

set(Server_tests "Server_tests")
set(tests_dir ${CMAKE_SOURCE_DIR}/tests/)
add_subdirectory(GoogleTest)

add_executable(${Server_tests} ${tests_dir}/server_tests.cpp)

target_link_libraries(${Server_tests}  gtest gtest_main) 