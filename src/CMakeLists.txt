cmake_minimum_required(VERSION 3.21)
project(add_two_numbers)

set(CMAKE_CXX_STANDARD 14)

add_executable(add_two_numbers main.cpp ${MY_INCLUDE_DIR}/listnode.h listnode.cpp)

target_link_libraries(add_two_numbers PRIVATE ${MY_INCLUDE_DIR})