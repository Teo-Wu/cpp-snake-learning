#include "Graphics.h"
#include <chrono>
#include <thread>
#include <time.h>
#include <cstdlib>

void Graphics::createBox() {
    box_ = newwin(LINES-2, COLS, 2, 0);
    box(box_, 0, 0);
    wrefresh(box_);
}

void Graphics::destroyBox() {
    wborder(box_, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(box_);
    delwin(box_);
}

void Graphics::init(const std::string& gameName) {
    srand((unsigned int) time(NULL));

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    nodelay(stdscr, true);
    curs_set(0);

    clear();

    mvprintw(0, (COLS/2) - 12, gameName.c_str());
    refresh();
    
    createBox();
}

void Graphics::finalize() {
    curs_set(1);
    destroyBox();
    endwin();
}

void Graphics::refreshScreen() {
    const float window_factor = (static_cast<float>(LINES) * 5.25f) / static_cast<float>(COLS);
    const uint32_t vertical_sleep_time = window_factor * sleep_time_;

    std::this_thread::sleep_for(std::chrono::microseconds(vertical_ ? vertical_sleep_time : sleep_time_));
    
    refresh();
    wrefresh(box_);
}

void Graphics::printChar(int y, int x, int img) {
    mvwaddch(box_, y, x, img);
    refresh();
    wrefresh(box_);
}

void Graphics::printMsg(int y, int x, const std::string& str) {
    if(y > 0 && x > 0) {
        mvwaddstr(box_, y, x, str.c_str());
    }
    else {
        if(y < 0) y += 2;
        if(x < 0) x = 0;
        mvaddstr(y, x, str.c_str());
    }

    refresh();
    wrefresh(box_);
}

char Graphics::readChar(int y, int x) {
    refresh();
    wrefresh(box_);
    return mvwgetch(box_, y, x);
}

int Graphics::readInpt() {
    return getch();
}

void Graphics::advanceDifficulty() {
    if (sleep_time_ > DIFFICULTY_CAP) {
        sleep_time_ -= DIFFICULTY_CHANGE;
    }
}

Graphics& Graphics::get() {
    static Graphics graphics;
    return graphics;
}

void Graphics::setVertical(bool value) {
    vertical_ = value;
}