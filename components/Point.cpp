#include "Point.h"

Point::Point(uint32_t y, uint32_t x, int img) {
    // TODO: implement constructor
    // should copy x,y and image
}

Point::~Point() {
    // TODO: implement destructor
    // should hide the point (hint: function for this already exists)
}

void Point::setPoint(uint32_t y, uint32_t x) {
    // TODO: implement this setter
}

uint32_t Point::getX() const {
    // TODO: implement this getter
}

uint32_t Point::getY() const {
    // TODO: implement this getter
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