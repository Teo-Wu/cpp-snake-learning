#include <iostream>
#include <thread>
#include <chrono>

#include "components/Point.h"
#include "components/Snack.h"
#include "components/Snake.h"
#include "input-output/Graphics.h"

void mainL01() {
    Graphics::get().init("Learners Helper");

    Point p(10,10,'X');
    p.print();

    Graphics::get().refreshScreen();
    std::this_thread::sleep_for(std::chrono::seconds(10));

    Graphics::get().finalize();

    std::cout << "Helper QUIT" << std::endl;
}

void mainL02() {
    Graphics::get().init("Learners Helper 02");

    Point p(10,10);
    generateSnack(&p);

    Graphics::get().refreshScreen();
    std::this_thread::sleep_for(std::chrono::seconds(10));

    Graphics::get().finalize();

    std::cout << "Helper QUIT" << std::endl;
}

void mainL03() {
    Graphics::get().init("Learners Helper 03");

    Point p(10,10);

    for (uint32_t i = 0; i < 100; i++) {
        p.moveDown();
        Graphics::get().refreshScreen();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        p.moveRight();
        Graphics::get().refreshScreen();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    /*
    while(...) {
        // TODO: play with this
    }
    */

    /*
    do {
        // TODO: play with this
    } while (...)
    */

    Graphics::get().finalize();

    std::cout << "Helper QUIT" << std::endl;
}

void mainL04() {
    Graphics::get().init("Learners Helper 04");

    Snake snake;

    for (uint32_t i = 0; i < 100; i++) {
        snake.moveDown();
        Graphics::get().refreshScreen();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        snake.moveRight();
        Graphics::get().refreshScreen();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    Graphics::get().finalize();

    std::cout << "Helper QUIT" << std::endl;
}

void mainL06() {
    Graphics::get().init("Learners Helper 06");

    Snake snake;

    // TODO: Now the snake will eventually crash into the lower wall which we detect and then abort
    // TODO: Figure out how to test the bit-itself and bit-snack functions yourself

    while(true) {
        snake.moveDown();
        Graphics::get().refreshScreen();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        if (snake.hasCrashedWall()) break;
    }

    Graphics::get().finalize();

    std::cout << "Helper QUIT" << std::endl;
}

int main() {
    mainL06();
    return 0;
}