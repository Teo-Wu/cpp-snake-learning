#include "Point.h"

Point::Point(uint32_t y, uint32_t x, int img)
    : x_ {x}, y_ {y}, img_ {img}
{ }

void Point::setPoint(uint32_t y, uint32_t x) {
    x_ = x;
    y_ = y;
}

uint32_t Point::getX() const {
    return x_;
}

uint32_t Point::getY() const {
    return y_;
}

void Point::moveUp() {
    y_--;
}

void Point::moveDown() {
    y_++;
}

void Point::moveLeft() {
    x_--;
}

void Point::moveRight() {
    x_++;
}

int Point::getImg() const {
    return img_;
}

void Point::setImg(int image){
    img_ = image;
}

void Point::print() const {
    Graphics::get().printChar(y_, x_, img_);
}

void Point::clear() {
    img_ = ' ';
    print();
}