#include "Point.h"
#include <iostream>
using namespace std;
Point::Point(uint32_t y, uint32_t x, int img) {
    x_=x;
    y_=y;
    img_=img;
}

Point::~Point() {
    clear();
    cout<< "destructed"<<endl;
}

void Point::setPoint(uint32_t y, uint32_t x) {
    y_=y;
    x_=x;
}

uint32_t Point::getX() const {
    return x_;
}

uint32_t Point::getY() const {
    return y_;
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