#include <stdio.h>

#include "header.h"
#include "getKey.h"
//Until e isnt pressed this waits
void waitForKey() {
    char pressedKey;
    while (pressedKey != 'e') {
        pressedKey = getKey();
    }
}
//Explains the player how this game is played
void tutorialHeader() {
    printf("#   Player 1 movement : W-S     #\n");
    printf("#   Player 2 movement : K-M     #\n");
    printf("#                               #\n");
    printf("#  First to get to 5 points     #\n");
    printf("#            wins!              #\n");
    printf("#      To beginn press E        #\n");
    printf("#################################\n");

    waitForKey();
}
//First header what starts in game
void header() {
    printf("#################################\n");
    printf("#         TERMINAL PONG         #\n");
    printf("#    Made by Botond.Payerhofer  #\n");
    printf("#       1AHIF HTL Pinkafeld     #\n");
    printf("#################################\n");
    tutorialHeader();
}
//Displays who won or lost
void gameOver(int winner) {
    printf("#################################\n");
    if (winner == 1) {
        printf("#        Player 1 wins          #\n");
    }
    if (winner == 2) {
        printf("#        Player 2 wins          #\n");
    }
    printf("#################################\n");

    tutorialHeader();
}