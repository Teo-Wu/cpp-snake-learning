#include <iostream>
#include <thread>
#include <chrono>

#include "components/Point.h"
#include "components/Snack.h"
#include "input-output/Graphics.h"

void mainL01() {
    Graphics::get().init("Learners Helper");

    Point p(10,10,'X');

    std::this_thread::sleep_for(std::chrono::seconds(10));

    Graphics::get().finalize();

    std::cout << "Helper QUIT" << std::endl;
}

void mainL02() {
    Graphics::get().init("Learners Helper 02");

    Point p(10,10);
    generateSnack(&p);

    std::this_thread::sleep_for(std::chrono::seconds(10));

    Graphics::get().finalize();

    std::cout << "Helper QUIT" << std::endl;
}

int main() {
    mainL02();
    return 0;
}