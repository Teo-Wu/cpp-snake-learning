#include "Snack.h"

void generateSnack(Point* snack){
    // TODO: implement me
    // should set a random position for the point, update its character/image and display the point
    // x should be between (0, GAME_RIGHT_WALL_X)
    // y should be between (0, GAME_BOTTOM_WALL_Y)
    // not including those values
    uint32_t randomx = 1 + (rand() % GAME_RIGHT_WALL_X);
    uint32_t randomy = 1 + (rand() % GAME_BOTTOM_WALL_Y);
    snack->setPoint(randomy,randomx);
    snack->setImg(SNACK_CHAR);

}
