cmake_minimum_required(VERSION 3.21)
project(myexec LANGUAGES CXX)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../QT6CMake/build")
find_package(yourlibrary REQUIRED)

add_executable(myexec main.cpp)
target_link_libraries(myexec PUBLIC yourlibrary::yourlibrary)