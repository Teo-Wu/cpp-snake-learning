#include "Snack.h"

#include <random>

void generateSnack(Point* snack){
    std::random_device dev;
    static std::mt19937 prng(dev());
    static std::uniform_int_distribution<std::mt19937::result_type> distX(0, GAME_RIGHT_WALL_X);
    static std::uniform_int_distribution<std::mt19937::result_type> distY(0, GAME_BOTTOM_WALL_Y);

    const uint32_t x = distX(prng);
    const uint32_t y = distY(prng);
    
    snack->setImg(SNACK_CHAR);
    snack->setPoint(y, x);
    snack->print();
}