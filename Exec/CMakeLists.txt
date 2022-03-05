cmake_minimum_required(VERSION 3.14)
project(somexec)

add_definitions(${MY_PROJECT_DEFINITIONS})
include_directories(${MY_PROJECT_INCLUDE_DIRS})

if (WIN32) 
    add_executable(${PROJECT_NAME} WIN32 main.cpp)
elseif(UNIX)
    add_executable(${PROJECT_NAME} main.cpp)
endif()

target_link_libraries(${PROJECT_NAME} MY_PROJECT)