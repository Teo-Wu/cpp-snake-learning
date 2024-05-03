#include <iostream>
#include <thread>
#include <chrono>

#include "components/Point.h"
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

int main() {
    mainL01();
    return 0;
}