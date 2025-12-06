#include "frameManager.h"
#include "getKey.h"

int player_location_x = 2;
int player_location_y = 5;

int player2_location_x = 49;
int player2_location_y = 5;

const int map_x = 50;
const int map_y = 10;

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
}

int main(void) {
    int i = 0;
    while (1) {
        i++;
        player_movement();
        setSize(map_x, map_y);
        setPlayerLocation(player_location_x ,player_location_y);
        setPlayerDesign('I');
        setObject1(player2_location_x ,player2_location_y ,'I');
        setObject2(25 , 5 , 'o');
        setLineDesign('#');
        scoreBoard(i, i);
        frameUpdate();
    }
}