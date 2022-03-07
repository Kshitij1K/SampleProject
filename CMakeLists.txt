cmake_minimum_required(VERSION 3.21)

set(CMAKE_MAKE_PROGRAM $ENV{MAKE})
set(CMAKE_SUPPORT_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_subdirectory(QT6CMake)
add_subdirectory(Exec)

