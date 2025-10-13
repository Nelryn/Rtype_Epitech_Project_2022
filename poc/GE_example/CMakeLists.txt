CMAKE_MINIMUM_REQUIRED(VERSION 3.17)

project(tgg)

FetchContent_MakeAvailable(sfml)
if(NOT sfml_POPULATED)
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

set(SRC main.cpp src/Game.cpp src/Window.cpp)

set(INC include/Game.hpp include/Window.hpp)

add_executable(tgg ${SRC} ${INC})
