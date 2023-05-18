cmake_minimum_required(VERSION 3.25)
project(Tic)

set(CMAKE_CXX_STANDARD 23)

add_executable(Tic main.cpp Players.cpp Screen.cpp Game.cpp Board.cpp Screen.h)
