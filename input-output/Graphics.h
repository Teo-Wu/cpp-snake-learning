#pragma once

#include <curses.h>
#include <string>

static constexpr int UP = KEY_UP;
static constexpr int DOWN = KEY_DOWN;
static constexpr int LEFT = KEY_LEFT;
static constexpr int RIGHT = KEY_RIGHT;
static constexpr int EXIT_GAME = 'q';

static constexpr int GAME_TOP_WALL_Y = 1;
const int GAME_BOTTOM_WALL_Y = LINES - 4;
static constexpr int GAME_LEFT_WALL_X = 1;
const int GAME_RIGHT_WALL_X = COLS - 2;

class Graphics {
private:
    unsigned int sleep_time_ = 40000000;
    WINDOW* box_ = NULL;

    Graphics();
    void createBox();
    void destroyBox();

public:
    static Graphics& get();
    void init(const std::string& game_name);
    void finalize();

    void refreshScreen();
    void printChar(int y, int x, int img);
    void printMsg(int y, int x, const std::string& str);
    char readChar(int y, int x);
    int readInpt();

    void advanceDifficulty();
};

