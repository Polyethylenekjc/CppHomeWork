cmake_minimum_required(VERSION 3.0)

project(HomeWork)

include_directories("../inc")

set(EXECUTABLE_OUTPUT_PATH ../bin)
aux_source_directory("../src" SRC_LIST)
add_executable(main ../main.cpp ${SRC_LIST})
