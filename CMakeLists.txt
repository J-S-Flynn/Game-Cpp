cmake_minimum_required(VERSION 3.16)
project(game)

set(CMAKE_CXX_STANDARD 14)

add_executable(game jsf/main.cpp jsf/src/Game.cpp jsf/src/Game.h jsf/src/TextureManager.h jsf/src/TextureManager.cpp jsf/src/GameObject.h jsf/src/GameObject.cpp)

target_link_libraries(game PRIVATE SDL2)
target_link_libraries(game PRIVATE SDL2_image)