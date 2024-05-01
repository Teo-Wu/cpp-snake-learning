#pragma once

#include <curses.h>
#include <string>

static constexpr int UP = KEY_UP;
static constexpr int DOWN = KEY_DOWN;
static constexpr int LEFT = KEY_LEFT;
static constexpr int RIGHT = KEY_RIGHT;
static constexpr int EXIT_GAME = 'q';

static constexpr uint32_t GAME_TOP_WALL_Y = 1;
static constexpr uint32_t GAME_LEFT_WALL_X = 1;
#define GAME_BOTTOM_WALL_Y (LINES - 4)
#define GAME_RIGHT_WALL_X (COLS - 2)

static constexpr uint32_t DIFFICULTY_BEGIN = 40000;
static constexpr uint32_t DIFFICULTY_CAP = 28000;
static constexpr uint32_t DIFFICULTY_CHANGE = 1000;

class Graphics {
private:
    bool vertical_ = false;
    uint32_t sleep_time_ = DIFFICULTY_BEGIN;
    WINDOW* box_ = nullptr;

    Graphics() = default;
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
    void setVertical(bool value);
};

