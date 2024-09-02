cmake_minimum_required(VERSION 3.20)
project(tests)
enable_testing()

set(Server_tests "tserver")
set(Client_tests "tclient")
set(tests_dir ${CMAKE_SOURCE_DIR}/tests/)
add_subdirectory(GoogleTest)


add_executable(${Server_tests} ${tests_dir}/server_tests.cpp)
add_executable(${Client_tests} ${tests_dir}/client_test.cpp)

target_link_libraries(${Server_tests}  gtest gtest_main)
target_link_libraries(${Client_tests}  gtest gtest_main) 

add_test(NAME Server_test COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${Server_tests})
add_test(NAME Client_test COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/${Client_tests})