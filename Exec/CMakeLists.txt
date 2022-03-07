cmake_minimum_required(VERSION 3.21)
project(myexec CXX)

list(APPEND CMAKE_PREFIX_PATH "../QT6CMake")

# Also finds Qt
find_package(yourlibrary REQUIRED)

add_executable(myexec main.cpp)
target_link_libraries(myexec PUBLIC yourlibrary::yourlibrary)
