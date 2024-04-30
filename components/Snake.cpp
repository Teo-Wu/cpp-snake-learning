#include "Snake.h"

#include <iostream>

Snake::Snake(uint32_t headY, uint32_t headX)
    :direction_{LEFT}
{
    snake_.push_back(Point{headY, headX, '>'});

    for (uint32_t i = 1; i <= SNAKE_DEFAULT_SIZE - 1; i++) {
        snake_.push_back(Point{headY, headX + i, SNAKE_BODY_CHAR});
    }
}

bool Snake::isBitten() const {
    const Point& head = snake_.front();

    for (const Point& part : snake_) {
        if (part.getX() == head.getX() && part.getY() == head.getY()) {
            return true;
        }
    }

    return false;
}

bool Snake::hasBitSnack(uint32_t snackY, uint32_t snackX) const {
    return snake_.front().getY() == snackY && snake_.front().getX() == snackX;
}

bool Snake::hasCrashedWall() const {
    const Point& head = snake_.front();

    return (head.getY() < GAME_TOP_WALL_Y)    ||
           (head.getY() > GAME_BOTTOM_WALL_Y) ||
           (head.getX() < GAME_LEFT_WALL_X)   ||
           (head.getX() > GAME_RIGHT_WALL_X);
}

uint32_t Snake::getSize() const {
    return snake_.size();
}

void Snake::incSize(){
    const auto tail = std::prev(snake_.end());
    const uint32_t tailX = tail->getX();
    const uint32_t tailY = tail->getY();

    const auto prev = std::prev(tail);
    const uint32_t prevX = prev->getX();
    const uint32_t prevY = prev->getY();

    if (prevY == tailY){ 
        // if the two last parts are on the same 'height' (horizontal tail direction)

        if (prevX < tailX) {
            // if the tail continues to the left:
            // add one part to the right of the tail
            snake_.push_back(Point{tailY, tailX + 1, SNAKE_BODY_CHAR}); 
        }
        else {
            // if the tail continues to the right:
            // add one part to the left of the tail
            snake_.push_back(Point{tailY, tailX - 1, SNAKE_BODY_CHAR});
        }
    }
    else {
        // if the two last parts are on the same 'width' (vertical tail direction)

        if (prevY < tailY) {
            // if the tail continues to the upper side:
            // add one part facing down
            snake_.push_back(Point{tailY + 1, tailX, SNAKE_BODY_CHAR});
        }
        else {
            // if the tail continues to the lower side:
            // add one part facing up
            snake_.push_back(Point{tailY - 1, tailX, SNAKE_BODY_CHAR});
        }
    }
}

void Snake::updateHead(){
    switch (direction_) {
    case UP:
        snake_.front().moveUp();
        break;

    case DOWN:
        snake_.front().moveDown();
        break;

    case LEFT:
        snake_.front().moveLeft();
        break;

    case RIGHT:
        snake_.front().moveRight();
        break;
    }
}

void Snake::printSnake() const {
    //We print each element of the snake-list
    for (const Point& part : snake_){
        part.print();    
    }

    Graphics::get().refreshScreen();
}

void Snake::move(){
    // updates the tail by clearing it since
    // the snake moved forward (overwrites with ' ')
    snake_.back().clear();

    // iterate through the snake step by step
    // using iterators so that we can get prev
    // and iterate from back to front as we want to
    // update each element with the value of the next
    // and would otherwise overwrite the next before
    // and not updating first as head is handled separately

    for (auto it = std::prev(snake_.end()); it != snake_.begin(); it--) {
        const auto prev = std::prev(it);
        it->setPoint(prev->getY(), prev->getX());
    }

    // update the head depending on movement
    updateHead();

    // print the updated snake
    printSnake();
}

void Snake::moveUp(){
    snake_.front().setImg('v');
    direction_ = UP;
    move();
}

void Snake::moveDown(){
    snake_.front().setImg('^');
    direction_ = DOWN;
    move();
}

void Snake::moveLeft(){
    snake_.front().setImg('>');
    direction_ = LEFT;
    move();
}

void Snake::moveRight(){
    snake_.front().setImg('<');
    direction_ = RIGHT;
    move();
}