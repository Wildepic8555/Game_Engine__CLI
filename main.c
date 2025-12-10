#include <stdlib.h>

#include "ball.h"
#include "frameManager.h"
#include "player.h"
#include "header.h"

//Player position variables and init places
//Define Map Size
const int map_x = 26;
const int map_y = 7;
//How much score to win
const int winningScore = 5;
//Player locations
int player_location_x = 6;
int player_location_y = 4;
int player2_location_x = 21;
int player2_location_y = 4;
//1 = Player 1 , 2 = Player 2
int winner;
//Ball location
int ball_location_x = 13;
int ball_location_y = 4;
//If true frame gen if not true then no framgen
bool gameIsRunning = true;
//Defines functions
void gameLoop();
void resetGame();
void getWinner();

int main(void) {
    header();
    while (1) {
        gameLoop();
        resetGame();
        gameOver(winner);
    }
}

//Main Loop
void gameLoop(){
    while (gameIsRunning) {
        player_movement(&player_location_y , &player2_location_y , map_y);
        ball_movement(&ball_location_x , &ball_location_y , map_y , player_location_y , player2_location_y);
        setSize(map_x, map_y);
        setPlayerLocation(player_location_x ,player_location_y);
        setPlayerDesign('(');
        setObject1(player2_location_x ,player2_location_y ,')');
        setObject2(ball_location_x , ball_location_y , 'o');
        setLineDesign('#');
        scoreBoard(returnLeftScore(), returnRightScore());
        frameUpdate();
        getWinner();
    }
}
//Gets if player 1 or 2 wins or is a draw
void getWinner() {
    if (returnLeftScore() > winningScore -1  || returnRightScore() > winningScore -1) {
        if (returnLeftScore() > returnRightScore()) {
            winner = 1;
        }
        if (returnRightScore() > returnLeftScore()) {
            winner = 2;
        }
        gameIsRunning = false;
    }
}
//Resets the game to null
void resetGame() {
    gameIsRunning = true;
    resetScore();
    system("clear");
}