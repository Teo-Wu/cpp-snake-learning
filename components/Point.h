#pragma once

#include "../input-output/Graphics.h"

class Point{
private:
    uint32_t x_;
    uint32_t y_;
    int img_;

public:
    Point(uint32_t y, uint32_t x, int img = '*');

    void setPoint(uint32_t y, uint32_t x);
    uint32_t getX() const;
    uint32_t getY() const;

    void moveUp();
    void moveDown();
    void moveLeft();
    void moveRight();

    int getImg() const;
    void setImg(int image);

    void print() const;
    void clear();
};