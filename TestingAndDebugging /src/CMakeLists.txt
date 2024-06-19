cmake_minimum_required(VERSION 3.5)
project(SortingSrc)
set(CMAKE_CXX_STANDARD 14)

set(SRC_LIB_NAME SortingSrc)
set(EXE_NAME SortInts)


add_library(${SRC_LIB_NAME} STATIC sorting.cpp sorting.h formatting.cpp formatting.h)
target_include_directories(${SRC_LIB_NAME}  PUBLIC .)
target_compile_options(${SRC_LIB_NAME}  PRIVATE -Wall -Wextra -Werror)

add_executable(${EXE_NAME} main.cpp)
target_link_libraries(${EXE_NAME} PRIVATE ${SRC_LIB_NAME})
target_compile_options(${EXE_NAME} PRIVATE -Wall -Wextra -Werror)
