#pragma once

#include "../game/Controller.h"

#include <iostream>
#include <string>

class Player{
private:
    std::string name_;
    uint32_t high_score_ = 0;
    uint32_t timesPlayed_ = 0;

public:
    Player(std::string name);

    void play();

    uint32_t getHighScore() const;
    const std::string& getName() const;
};