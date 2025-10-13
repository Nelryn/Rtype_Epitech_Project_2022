cmake_minimum_required(VERSION 3.17)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

project(r-type)

set(BUILD_SHARED_LIBS False)

add_compile_definitions(_WIN32_WINNT=0x0601)

include(FetchContent)

set(SFML_VERSION "2.6.x")

Set(FETCHCONTENT_QUIET FALSE)
FetchContent_Declare(
    boost
    GIT_REPOSITORY "https://github.com/boostorg/boost.git"
    GIT_TAG master
    GIT_SUBMODULES ${BOOST_REQD_SUBMODULES}
    GIT_PROGRESS TRUE
    CONFIGURE_COMMAND ""  # tell CMake it's not a cmake project
)

FetchContent_MakeAvailable(boost)

add_library(GE STATIC
    ${PROJECT_SOURCE_DIR}/GameEngine/Entity.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/Position.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/StateManager.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/PlayState.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/bg.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/Missile.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/ParseConfig.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/Factory.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/Move.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/Core.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/Window.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/EntityManager.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/Map.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/pugixml.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/JSONError.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/CoreError.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/MapError.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/FactoryError.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/Movable.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/RessourcesError.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/Quadtree.cpp
    ${PROJECT_SOURCE_DIR}/GameEngine/Collidable.cpp
)

FetchContent_Declare(
    sfml
    GIT_REPOSITORY "https://github.com/SFML/SFML.git"
    GIT_TAG        "${SFML_VERSION}"
)

FetchContent_MakeAvailable(sfml)

if(NOT sfml_POPULATED)
    FetchContent_Populate(sfml)
    add_subdirectory(${sfml_SOURCE_DIR} ${sfml_BINARY_DIR})
endif()

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/GameEngine/include
    ${PROJECT_SOURCE_DIR}/GameEngine/include/Interfaces
    ${PROJECT_SOURCE_DIR}/GameEngine/include/Error
    ${PROJECT_SOURCE_DIR}/Server/include
    ${PROJECT_SOURCE_DIR}/Client/include
    ${boost_SOURCE_DIR}/include
    ${sfml_SOURCE_DIR}/include
)

file(COPY ${PROJECT_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR}/Client/)

file(GLOB PROJECT_FILES_CLIENT
    ${PROJECT_SOURCE_DIR}/Client/src/*.cpp
)

file(GLOB PROJECT_FILES_SERVER
    ${PROJECT_SOURCE_DIR}/Server/src/*.cpp
)

file(COPY ${PROJECT_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR}/Client)
file(COPY ${PROJECT_SOURCE_DIR}/Configuration DESTINATION ${CMAKE_BINARY_DIR}/Client)


target_link_libraries(GE
    sfml-graphics
    sfml-window
    sfml-system
    sfml-audio
    boost_system
    boost_json
    boost_filesystem
    boost_regex
    boost_thread
    boost_chrono
    boost_property_tree
    boost_asio
)

link_directories(${CMAKE_SOURCE_DIR}/lib)

add_subdirectory(${PROJECT_SOURCE_DIR}/Server)

add_subdirectory(${PROJECT_SOURCE_DIR}/Client)
