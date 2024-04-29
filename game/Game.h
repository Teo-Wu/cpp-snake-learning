#pragma once

#include "Controller.h"
#include "../components/Snake.h"
#include "../input-output/Player.h"

#include <string>

class SnakeGame{
private:
    std::string gameName;
    std::list<Player> players;
    unsigned int highScore;
    std::string bestPlayer;
    
    void play(std::string playerName);
    void addPlayer(std::string playerName);

public:
    SnakeGame(); //intialize graphics and set the game screen
    ~SnakeGame();

    
    unsigned int getHighScore(void);
    std::string getBestPlayer(void);

    //print the statistics (highest score & games played) of each player
    //void printGameStatistics(void);

    void play(void);
};