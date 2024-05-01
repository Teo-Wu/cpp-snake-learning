#include "Controller.h"

#include <string>
#include <iostream>

Controller::Controller()
    : input_{0}, score_{0}, snack_{Point(0,0,0)}
{
    generateSnack(&snack_);
}

uint32_t Controller::getCurrScore() const {
    return score_;
}

void Controller::resetScore() {
    score_ = 0;
}

void Controller::printScore(uint32_t score) const {
    const std::string str = "Score: " + std::to_string(score); 
    // locate message at (-1,-1) because otherwise it'll be printed inside the game box
    Graphics::get().printMsg(-1, -1, str);
}

int Controller::act() {
    if (snake_.hasBitSnack(snack_.getY(), snack_.getX())) {
        score_ += 10;
        snake_.incSize();

        generateSnack(&snack_);
        Graphics::get().advanceDifficulty();
        
        printScore(score_);
    }

    switch (input_) {
    case UP:
        snake_.moveUp();
        Graphics::get().setVertical(true);
        break;
    case DOWN:
        snake_.moveDown();
        Graphics::get().setVertical(true);
        break;
    case LEFT:
        snake_.moveLeft();
        Graphics::get().setVertical(false);
        break;
    case RIGHT:
        snake_.moveRight();
        Graphics::get().setVertical(false);
        break;
    default:
        snake_.move();
    }

    Graphics::get().refreshScreen();

    if (snake_.isBitten() || snake_.hasCrashedWall()) {
        return DEFEAT;
    }

    return 0;
}

int Controller::readInput() {
    input_ = Graphics::get().readInpt();
    return input_;
}

bool Controller::wantsToQuit() const {
    return input_ == EXIT_GAME;
}
