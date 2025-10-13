cmake_minimum_required(VERSION 3.17)

project(r-type_client)

add_executable(r-type_client ${PROJECT_FILES_CLIENT})

target_link_libraries(r-type_client PUBLIC sfml-graphics sfml-window sfml-audio Boost::asio)
target_link_libraries(r-type_client PUBLIC GE)
