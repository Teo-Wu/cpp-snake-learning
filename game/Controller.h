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
    void readInput();

public:
    Controller();

    int act();

    bool wantsToQuit() const;

    uint32_t getScore() const;
};
