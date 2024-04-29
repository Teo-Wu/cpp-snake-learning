#pragma once

#include "../game/Controller.h"

#include <iostream>
#include <string>

class Player{
private:
    std::string name;
    unsigned int points;
    unsigned int timesPlayed;
    
public:
    Player();
    Player(std::string _name);
    ~Player();

    std::pair<std::string, unsigned int> play(void);

    //Point managment methods
    unsigned int getPoints(void);
    void addPoints(unsigned int _points);

    std::string getName(void);
};