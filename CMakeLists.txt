cmake_minimum_required(VERSION 3.16)
project(FlappyBird)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror")

add_executable(FlappyBird main.cpp
        player.cpp
        player.h
        Scene.cpp
        Scene.h
        Pipe.cpp
        Pipe.h)

target_link_libraries(FlappyBird raylib)
