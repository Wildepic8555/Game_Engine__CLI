//
// Created by wildepic on 12/9/25.
//

#include "player.h"
#include "getKey.h"

//player 1 and 2 movement with w,s,k,m
void player_movement(int *player_location_y , int *player2_location_y , int map_y) {
    char pressedKey = getKey();
    if ('w' == pressedKey) {
        if (*player_location_y > 1) {
            *player_location_y = *player_location_y - 1;
        }
    }
    else if ('s' == pressedKey) {
        if (*player_location_y < map_y ) {
            *player_location_y = *player_location_y + 1;
        }
    }
    else if ('k' == pressedKey) {
        if (*player2_location_y > 1) {
            *player2_location_y = *player2_location_y -1;
        }
    }
    else if ('m' == pressedKey) {
        if (*player2_location_y < map_y ) {
            *player2_location_y = *player2_location_y +1;
        }
    }
}