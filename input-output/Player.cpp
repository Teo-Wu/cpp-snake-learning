#include "Player.h"

Player::Player(std::string name)
    : name_{name}
{}

const std::string& Player::getName() const {
    return name_;
}

uint32_t Player::getHighScore() const {
    return high_score_;
}

void Player::play(){
    Controller controller;

    while (controller.wantsToQuit() == false) {
        controller.readInput();

        if (controller.act() == DEFEAT) {
            break;
        }
    }

    const uint32_t score = controller.getCurrScore();
    controller.resetScore();

    if (score > high_score_) {
        high_score_ = score;
    }
}