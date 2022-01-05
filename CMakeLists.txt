cmake_minimum_required(VERSION 3.21)
project(linuxproginterface C)

set(CMAKE_C_STANDARD 17)

add_library(error_functions STATIC lib/error_functions.c lib/error_functions.c)
target_include_directories(error_functions PUBLIC include)

add_executable(copy fileio/copy.c)
target_link_libraries(copy PUBLIC error_functions)