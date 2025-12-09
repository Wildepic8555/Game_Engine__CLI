//
// Created by wildepic on 12/9/25.
//

#include <time.h>
#include "ball.h"

#include <stdio.h>
#include <stdlib.h>

int ballStartX = 13;
int ballStartY = 4;
int sideMultiplier;
int minusMultiplier = -1;
int randomX = 1;
int randomY = 1;
int currentTick = 0;
int scoreLeft = 0;
int scoreRight = 0;

void minusMultiplierFunc();
void sideMultiplierFunc();
void randomSite();
void scoreCheck(int x , int y , int py , int py2);

void ball_movement(int *ball_location_x , int *ball_location_y , int map_height , int player_location_y , int player2_location_y) {
    //When ball in mid choose random site to go (left , right)
    if (*ball_location_x == ballStartX && *ball_location_y == ballStartY) {
        randomSite();
    }
    currentTick++;
    //After 12 frames update ball
    if (currentTick == 12) {
        minusMultiplierFunc();
        sideMultiplierFunc();

        //If ball up ,set ball movement down
        if (*ball_location_y < 3) {
            minusMultiplier = 1;
        }
        //If ball down ,set ball movement up
        if (*ball_location_y > 5) {
            minusMultiplier = -1;
        }

        //Movement of ball
        *ball_location_x = *ball_location_x + randomX;
        *ball_location_y = *ball_location_y + randomY;

        //Makes ball go to mid
        if (*ball_location_x < 2 || *ball_location_x > 25) {
            srand(time(NULL));
            *ball_location_x = ballStartX;
            *ball_location_y = (rand() % map_height +1);
            ballStartY = *ball_location_y;
        }
        //Makes ball go from player to player 2
        if (*ball_location_y == player_location_y && *ball_location_x < 4) {
            sideMultiplier = 1;
        }
        //Makes ball go from player2 to player
        if (*ball_location_y == player2_location_y && *ball_location_x > 23) {
            sideMultiplier = -1;
        }
        scoreCheck(*ball_location_x , *ball_location_y , player_location_y , player2_location_y);
        currentTick = 0;
    }
}
//Makes switching of up down
void minusMultiplierFunc() {
    if (minusMultiplier == -1) {
        if (randomY >= 0) {
            randomY = randomY * -1;
        }
    }
    else {
        if (randomY <= 0) {
            randomY = randomY * -1;
        }
    }
}
//Makes switching of left right side
void sideMultiplierFunc() {
    if (sideMultiplier == -1) {
        if (randomX >= 0) {
            randomX = randomX * -1;
        }
    }
    else {
        if (randomX <= 0) {
            randomX = randomX * -1;
        }
    }
}
//Return the score of left side
int returnLeftScore() {
    return scoreLeft;
}
//Return the score of right side
int returnRightScore() {
    return scoreRight;
}
//Makes ball go left or right
void randomSite() {
    srand(time(NULL));

    sideMultiplier = rand() % 2 + 1;

    if (sideMultiplier == 1) {
        sideMultiplier = -1;
    }
    else {
        sideMultiplier = 1;
    }
}
//Check if 1 player scored
void scoreCheck(int x , int y , int py , int py2) {
    if (x > 24 && y != py2) {
        scoreLeft++;
    }
    if (x < 3 && y != py) {
        scoreRight++;
    }
}

