#include <stdio.h>
#include <unistd.h>

#include "frameManager.h"
#include "getKey.h"

int player_location_x = 2;
int player_location_y = 3;

int player2_location_x = 10;
int player2_location_y = 1;

const int map_x = 11;
const int map_y = 5;

void player_movement() {
    char pressedKey = getKey();
    if ('w' == pressedKey) {
        if (player_location_y > 1) {
            player_location_y--;
        }
    }
    else if ('s' == pressedKey) {
        if (player_location_y < map_y ) {
                player_location_y++;
        }
    }
    else if ('k' == pressedKey) {
        if (player2_location_y > 1) {
            player2_location_y--;
        }
    }
    else if ('m' == pressedKey) {
        if (player2_location_y < map_y ) {
            player2_location_y++;
        }
    }
    if ('e' == pressedKey) {
        return;
    }
}

int main(void) {
    int i = 0;
    while (1) {
        i++;
        player_movement();
        setSize(map_x, map_y);
        setPlayerLocation(player_location_x ,player_location_y);
        setPlayerDesign('P');
        setLineDesign('#');
        setObject1(player2_location_x ,player2_location_y ,'I');
        scoreBoard(i, i);
        frameUpdate();
    }
    return 5;
}