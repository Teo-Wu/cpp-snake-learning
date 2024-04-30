#pragma once

#include <string>
#include <vector>

#include "Controller.h"
#include "../components/Snake.h"
#include "../input-output/Player.h"

class SnakeGame{
private:
    const std::string game_name_ = "Snake Game for C++ Course";
    std::vector<Player> players_;

    uint32_t high_score_ = 0;
    std::string best_player_ = "None";
    
    void play(const std::string& name);
    void addPlayer(const std::string& name);

public:
    uint32_t getHighScore() const;
    const std::string& getBestPlayer() const;
    void printGameStatistics() const;

    void play();
};