include(CMakeFindDependencyMacro)

# write it like you find_package of your cmadke scripts
find_dependency(Qt6 COMPONENTS Core REQUIRED)
find_dependency(Qt6 COMPONENTS Widgets REQUIRED)

include(yourlibrary-targets.cmake)