cmake_minimum_required(VERSION 3.15.3)
project(BattleShip)

set(CMAKE_CXX_STANDARD 14)

add_executable(BattleShip main.cpp HuntDestroy.cpp HuntDestroy.h CheatingAI.cpp CheatingAI.h RandomAI.cpp RandomAI.h playLoop.cpp playLoop.h HumanPlayer.cpp HumanPlayer.h Board.cpp Board.h Player.cpp Player.h AIPlayer.cpp AIPlayer.h)
