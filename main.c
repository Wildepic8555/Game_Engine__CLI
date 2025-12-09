#include "ball.h"
#include "frameManager.h"
#include "player.h"
#include "header.h"

//Player position variables and init places
int player_location_x = 2;
int player_location_y = 4;

int player2_location_x = 25;
int player2_location_y = 4;

int ball_location_x = 13;
int ball_location_y = 4;

//Define Map Size
const int map_x = 26;
const int map_y = 7;

bool gameIsRunning = true;

void gameLoop();
void resetGame();

int main(void) {
    header();
    while (1) {
        gameLoop();
        gameOver();
        resetGame();
    }
}

//Main Loop
void gameLoop(){
    while (gameIsRunning) {
        player_movement(&player_location_y , &player2_location_y , map_y);
        ball_movement(&ball_location_x , &ball_location_y , map_y , player_location_y , player2_location_y);
        setSize(map_x, map_y);
        setPlayerLocation(player_location_x ,player_location_y);
        setPlayerDesign('I');
        setObject1(player2_location_x ,player2_location_y ,'I');
        setObject2(ball_location_x , ball_location_y , 'o');
        setLineDesign('#');
        scoreBoard(returnLeftScore(), returnRightScore());
        frameUpdate();
    }
}

void resetGame() {}
