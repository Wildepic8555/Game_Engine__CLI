//
// Created by wildepic on 12/9/25.
//

#ifndef GAME_ENGINE_BALL_H
#define GAME_ENGINE_BALL_H

int returnLeftScore();
int returnRightScore();

void ball_movement(int *ball_location_x , int *ball_location_y , int map_height ,int player_location_y , int player2_location_y);
void randomMovement();
void resetScore();

#endif //GAME_ENGINE_BALL_H