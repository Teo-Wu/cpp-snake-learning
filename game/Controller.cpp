#include "Controller.h"

#include <string>
#include <iostream>

Controller::Controller()
    : input_{0}, score_{0}, snack_{Point(0,0,0)}
{
    generateSnack(&snack_);
}

void Controller::printScore(uint32_t score) const {
    const std::string str = "Score: " + std::to_string(score); 
    // locate message at (-1,-1) because otherwise it'll be printed inside the game box
    Graphics::get().printMsg(-1, -1, str);
}

int Controller::act() {
    readInput();

    if (snake_.hasBitSnack(snack_.getY(), snack_.getX())) {
        score_ += 10;
        snake_.incSize();

        generateSnack(&snack_);
        Graphics::get().advanceDifficulty();
        
        printScore(score_);
    }

    // TODO: perform action depending on value of input_ - see "Snake::updateHead" for some guidance

    Graphics::get().refreshScreen();

    // TODO: handle bit-itself and crashed-wall case by returning DEFEAT

    return 0;
}

void Controller::readInput() {
    input_ = Graphics::get().readInpt();
}

bool Controller::wantsToQuit() const {
    return input_ == EXIT_GAME;
}

uint32_t Controller::getScore() const {
    return score_;
}
