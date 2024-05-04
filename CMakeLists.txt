cmake_minimum_required(VERSION 2.8)
project(snake)

find_package(Curses REQUIRED)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

set(SOURCES
    components/Point.cpp
    components/Snack.cpp
    input-output/Graphics.cpp
    
    main.cpp
)

include_directories(${CURSES_INCLUDE_DIR})
add_executable(snake ${SOURCES})
target_link_libraries(snake ${CURSES_LIBRARIES})