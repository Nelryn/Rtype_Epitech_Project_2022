cmake_minimum_required(VERSION 3.17)

project(r-type_server)

add_executable(r-type_server ${PROJECT_FILES_SERVER})

target_link_libraries(r-type_server PUBLIC Boost::asio)
if (!MSVC)
    target_link_libraries(r-type_server PUBLIC pthread)
endif()

target_link_libraries(r-type_server PUBLIC GE)
