cmake_minimum_required(VERSION 3.25)
project(Game_SeaBattle)

set(CMAKE_CXX_STANDARD 17)

add_executable(Game_SeaBattle main.cpp Game.cpp Game.h List.cpp List.h Functions.cpp Functions.h Check_Input.cpp Check_Input.h Player_human.cpp Player_human.h Sea_Monster.cpp Sea_Monster.h Coordinate.cpp Coordinate.h Player.cpp Player.h Battlefield_player.cpp Battlefield_player.h Battlefield_enemy.cpp Battlefield_enemy.h Battlefield.cpp Battlefield.h Cell.cpp Cell.h Ship.cpp Ship.h Direction.cpp Direction.h)
