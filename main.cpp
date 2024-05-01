#include <iostream>
#include <thread>
#include <chrono>

#include "components/Point.h"
#include "input-output/Graphics.h"

void mainL01() {
    Graphics::get().init("Learners Helper");

    Point p(10,10,'X');
    p.print();

    std::this_thread::sleep_for(std::chrono::seconds(10));

    Graphics::get().finalize();

    std::cout << "Helper QUIT" << std::endl;
}

int main() {
    mainL01();
    return 0;
}