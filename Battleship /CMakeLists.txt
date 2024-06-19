cmake_minimum_required(VERSION 3.15.3)
project(BattleShip)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattleShip main.cpp Player.cpp Player.h Board.cpp Board.h playLoop.cpp playLoop.h)
