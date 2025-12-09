cmake_minimum_required(VERSION 4.0)
project(Game_Engine C)

set(CMAKE_C_STANDARD 23)

add_executable(Game_Engine main.c
        frameDraw.c
        frameDraw.h
        getKey.c
        getKey.h
        frameManager.c
        frameManager.h
        scoreboard_draw.c
        scoreboard_draw.h
        player.c
        player.h
        header.c
        header.h
        ball.c
        ball.h
)
