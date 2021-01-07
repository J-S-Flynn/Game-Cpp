cmake_minimum_required(VERSION 3.16)
project(game)

set(CMAKE_CXX_STANDARD 14)

add_executable(game jsf/main.cpp jsf/gameLoop/Game.cpp jsf/gameLoop/Game.h)

target_link_libraries(game PRIVATE SDL2)