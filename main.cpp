#include <iostream>
#include <thread>
#include <chrono>
#include <algorithm>
#include "components/Point.h"
#include "components/Snack.h"
#include "input-output/Graphics.h"
void mainL01() {
    Graphics::get().init("Learners Helper");

    { Point p(10,10,'X');
    p.print(); 
    Graphics::get().refreshScreen();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    Graphics::get().refreshScreen();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    
    { Point p(20,30,'Y');
    p.print();
    Graphics::get().refreshScreen();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    Graphics::get().refreshScreen();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    Graphics::get().finalize();

    std::cout << "Helper QUIT" << std::endl;
}

void mainL02() {
    Graphics::get().init("Learners Helper 02");

     { Point p(10,10);
    generateSnack(&p);
    p.print();
    Graphics::get().refreshScreen();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    Graphics::get().refreshScreen();
    std::this_thread::sleep_for(std::chrono::seconds(1));
    Graphics::get().finalize();

    std::cout << "Helper QUIT" << std::endl;
}

void mainL03() {
    Graphics::get().init("Learners Helper 02");

    Point p(10,10);
    // for (uint32_t i = 0; i < std::min(GAME_BOTTOM_WALL_Y,GAME_RIGHT_WALL_X); i++) {
    //     p.print();
    //     p.moveDown();
    //     Graphics::get().refreshScreen();
    //     std::this_thread::sleep_for(std::chrono::milliseconds(10));
    //     p.moveRight();
    //     Graphics::get().refreshScreen();
    //     std::this_thread::sleep_for(std::chrono::milliseconds(10));
    // }

    // int i=0;
    // while(i<std::min(GAME_BOTTOM_WALL_Y,GAME_RIGHT_WALL_X)) {
    //     p.print();
    //     p.moveDown();
    //     Graphics::get().refreshScreen();
    //     std::this_thread::sleep_for(std::chrono::milliseconds(10));
    //     p.moveRight();
    //     Graphics::get().refreshScreen();
    //     std::this_thread::sleep_for(std::chrono::milliseconds(10));
    //     i++;
    // }
   
    int i=0;
    do {
        p.print();
        p.moveDown();
        Graphics::get().refreshScreen();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        p.moveRight();
        Graphics::get().refreshScreen();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        i++;
    } while (i<std::min(GAME_BOTTOM_WALL_Y,GAME_RIGHT_WALL_X));


    Graphics::get().finalize();

    std::cout << "Helper QUIT" << std::endl;
}

int main() {
    mainL03();
    return 0;
}