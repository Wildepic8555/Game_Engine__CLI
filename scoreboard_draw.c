//
// Created by wildepic on 11/29/25.
//

#include "scoreboard_draw.h"

#include <stdio.h>

int scoreBoardSize;
int scoreBoardDesign;
int scoreDrawScore;
int scoreDrawScore1;

//Calculates how many Digits of int number
int scoreDigitCalc(int number) {
    int digitLength = 0;
    if (number < 10) {
        digitLength = 1;
    }
    if (number > 9) {
        digitLength = 2;
    }
    if (number > 99) {
        digitLength = 3;
    }
    if (number > 999) {
        digitLength = 4;
    }
    return digitLength;
}

//Generates top and bottom line
void top_bottom_line() {
    int i = 0;
    while (i < scoreBoardSize) {
        i++;
        putchar(scoreBoardDesign);
    }
    printf("\n");
}

void scoreBoardMain() {
    //Calculates the length of score1 and 2
    int digitLength = scoreDigitCalc(scoreDrawScore);
    int digitLength1 = scoreDigitCalc(scoreDrawScore1);

    //Generates how many digits are missing from 4
    int missingDigits = 4 - digitLength;
    int missingDigits1 = 4 - digitLength1;

    int i = 0;
    //Generates distance between the two scores
    int middleLength = scoreBoardSize -(2*4) - 4 + missingDigits + missingDigits1 ;
    top_bottom_line();

    putchar(scoreBoardDesign);
    putchar(32);

    printf("%d", scoreDrawScore);

    //Makes middle  distance between the two
    while (i < middleLength) {
        i++;
        putchar(32);
    }

    printf("%d", scoreDrawScore1);

    putchar(32);
    putchar(scoreBoardDesign);
    printf("\n");
}

//The function bets called from frame manager
//Translates all the variables from frame manager to local
//And calls scoreBoardMain();
void scoreBoardManager(int score1 , int score2 , int sizeXScoreBaord , int design) {
    scoreBoardSize = sizeXScoreBaord + 2;
    scoreBoardDesign = design;
    scoreDrawScore = score1;
    scoreDrawScore1 = score2;
    scoreBoardMain();
}
