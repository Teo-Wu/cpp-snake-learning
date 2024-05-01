#include "Snake.h"

#include <iostream>

Snake::Snake(uint32_t headY, uint32_t headX)
    :direction_{LEFT}
{
    snake_.push_back(Point{headY, headX, '>'});

    for (uint32_t i = 1; i <= SNAKE_DEFAULT_SIZE; i++) {
        snake_.push_back(Point{headY, headX + i, SNAKE_BODY_CHAR});
    }
}

void Snake::updateHead() {
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
    default:
        std::cerr << "[x] This direction does not exist" << std::endl;
        // OOPS!
    }
}

void Snake::printSnake() const {
    // TODO: for each point in snake_ call point.print()

    Graphics::get().refreshScreen();
}

void Snake::move() {
    auto head = snake_.begin();
    auto second = std::next(snake_.begin());

    // TODO: the current tail of our snake shoudl be hidden

    // TODO: each element, from the tail to the second-to-head
    //       should move to the position of the element before it

    // update the previous to head node
    // by copying from head and setting
    // the image to be body instead of head
    *second = *head;
    second->setImg(SNAKE_BODY_CHAR);

    updateHead();

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

bool Snake::isBitten() const {
    const Point& head = snake_.front();

    // TODO: return true if any point of the snake has the same position as the head
    //       remember to skip the head as the snake is not flexible enough to bite off its own head

    return false;
}

bool Snake::hasBitSnack(uint32_t snackY, uint32_t snackX) const {
    const Point& head = snake_.front();
    
    // TODO: return true if the heads position is on the same coordinates as snack
    //       and return false otherwise
}

bool Snake::hasCrashedWall() const {
    const Point& head = snake_.front();

    return (head.getY() < GAME_TOP_WALL_Y)    ||
           (head.getY() > GAME_BOTTOM_WALL_Y) ||
           (head.getX() < GAME_LEFT_WALL_X)   ||
           (head.getX() > GAME_RIGHT_WALL_X);
}