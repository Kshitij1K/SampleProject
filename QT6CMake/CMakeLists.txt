cmake_minimum_required(VERSION 3.21)
project(yourlibrary CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_PREFIX_PATH $ENV{QTDIR})
set(CMAKE_INCLUDE_CURRENT_DIR ON)

# First, create your library. List all the files one by one. Don't use globs
add_library(yourlibrary src/mainwindow.cpp)

# Then add an alias of your library to enable target syntax
add_library(yourlibrary::yourlibrary ALIAS yourlibrary)

# Then, include gnuinstalldir to get the platform's standard directories:
include(GNUInstallDirs)

# Then, carefully add your include directories. All of your `target_include_directories` must look like this
target_include_directories(yourlibrary PUBLIC
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> # include directory in your build tree
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>       # include directory when installed
)

# Then, include Qt and link qt
find_package(Qt6 COMPONENTS Core Widgets REQUIRED)
target_link_libraries(yourlibrary PUBLIC Qt6::Core Qt6::Widgets)

# Now, create the install script. We install all header files under `include/yourlibrary` to install them in `<prefix>/include/yourlibrary`:
install(
  DIRECTORY include/yourlibrary
  DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} FILES_MATCHING PATTERN "*.hpp"
)

# We add `yourlibrary` target into the export set.
# The export set will contain all targets to be imported by the other project.
# It also installs the library to the install script so they are installed:
install(TARGETS yourlibrary EXPORT yourlibrary-targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Now, we install the export set. This will generate a CMake file exporting all the target for other projects to use:
install(EXPORT yourlibrary-targets
  DESTINATION "${CMAKE_INSTALL_DATADIR}/cmake/yourlibrary"
  NAMESPACE yourlibrary::
)

# Now, we also export the current buildtree. Other project will be able to import the project directly from a build dir:
configure_file(cmake/yourlibrary-config.cmake yourlibrary-config.cmake COPYONLY) 
export(
  EXPORT yourlibrary-targets
  NAMESPACE yourlibrary::
  FILE "${PROJECT_BINARY_DIR}/yourlibrary-targets.cmake"
)

# The file we created earlier:
install(
    FILES yourlibrary-config.cmake
    DESTINATION "${CMAKE_INSTALL_DATADIR}/cmake/yourlibrary"
)
