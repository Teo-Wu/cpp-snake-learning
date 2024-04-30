#pragma once

#include <memory>

#include "../input-output/Graphics.h"
#include "../components/Snake.h"
#include "../components/Point.h"

static constexpr int DEFEAT = -1;

class Controller {
private:
    Snake snake_;
    Point snack_;

    int input_;
    uint32_t score_;

    void printScore(uint32_t score) const;

public:
    Controller();

    uint32_t getCurrScore() const;

    void resetScore();
    int readInput();
    int act();

    bool wantsToQuit() const;
};