cmake_minimum_required(VERSION 3.14)

# if (WIN32)
#   set(CMAKE_SHARED_LIBRARY_PREFIX "")

# endif ()

set(CMAKE_MAKE_PROGRAM $ENV{MAKE})
set(CMAKE_CONFIGURATION_TYPES "Release;RelWithDebInfo" CACHE STRING "" FORCE)
set(CMAKE_SUPPORT_WINDOWS_EXPORT_ALL_SYMBOLS ON)
set(WINDOWS_EXPORT_ALL_SYMBOLS ON)

add_subdirectory(QT6CMake)
add_subdirectory(Exec)

