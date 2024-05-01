#pragma once

#include <vector>

#include "Point.h"
#include "Snack.h"

static constexpr int SNAKE_BODY_CHAR = 'o';
static constexpr uint32_t SNAKE_DEFAULT_SIZE = 4;

class Snake{
private:
    std::vector<Point> snake_;
    int direction_;

    void updateHead();
    void printSnake() const;

public:
    Snake(uint32_t headY = LINES/2, uint32_t headX = COLS/2);

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();
    void move();

    bool isBitten() const;
    bool hasBitSnack(uint32_t snackY, uint32_t snackX) const;
    bool hasCrashedWall() const;
};
