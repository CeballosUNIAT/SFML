cmake_minimum_required(VERSION 3.27)
project(SFML)

set(CMAKE_CXX_STANDARD 17)

add_executable(SFML main.cpp)

find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)

target_link_libraries(SFML PRIVATE sfml-system sfml-window sfml-graphics sfml-network)