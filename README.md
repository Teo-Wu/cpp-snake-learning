# Snake Game for learning C++

## Abstract

A simple snake game, with terminal GUI implemented using ncurses library.
Taken from Vissa Moutafis [LINK](https://github.com/VissaMoutafis/Snake-Game-in-Cpp) and heavily modified.

#### Required Knowledge:

This project is meant for those with a little programming experience in any other language or a general overview of programming concepts. If you can tell the terms "Object" and "Class" apart, know what a function is, know basic git and have used a command line before, then this project will teach you through exploring and solving challenges by yourself how to program C++. If you don't know these terms but can take a big challenge, then this is still a good starting point. Just try to figure out what is going on and you will learn a lot.

#### Resources:

- __[cppreference](https://en.cppreference.com/w/)__ for information on all elements of the language, quite detailed and might be overwhelming for beginners
- __[Cherno C++ Playlist](https://www.youtube.com/watch?v=18c3MTX0PK0&list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb)__ for an overview of all components of the language in a very beginner-friendly format
- __stackoverflow__ when you have a problem, most of the time, someone else has encountered it too, and you will find help and examples when web-searching and clicking on links to this site
- __[Tetris for Windows](https://youtu.be/8OK8_tHeCIA)__ code-along tetris video for the windows command line with good and beginner-friendly explanations

#### Controls:

- __Up-Arrow__ to go up.
- __Down-Arrow__ to go down.
- __Left-Arrow__ to go left.
- __Right-Arrow__ to go right.
- __q__ to exit game. 

---

## Prerequisities

You need to install the following packages:

- __ncurses__ : Terminal User Interface Library "ncurses"
- __cmake__ and __make__ : Build Tools
- __gcc__ or __clang__ : C/C++ Compiler

If you use MacOS then you must install homebrew for access to the packages. On Windows you must install and set up WSL to get a Linux command line.
Open up a terminal and type the folllowing commands:

```shell
# Most Linux distributions and WSL under Windows
~$ sudo apt-get install gcc make cmake libncurses5-dev libncursesw5-dev
# On MacOS
~$ brew install clang make cmake ncurses
# Or for FreeBSD
~$ sudo apt-get install clang make cmake ncurses

```
Now you are ready to use the repo.

---

## Downloading, Instalation and Running the Program

Now we will install and run the program, but first let's download the repo:

```shell
~$ git clone https://git.constantin-fuerst.com/constantin/snake
# cd in the directory
~$ cd snake
# select the correct branch for learning
~$ git checkout lessons
# or cheat and look at the solution / see what you will achieve with
~$ git checkout master
# run the helper script to build and execute
~$ bash build-and-run.sh
```

and begin your journey through C++!

---

## How to learn

- [ ] Perform Setup like above
- [ ] Run the game on __master__ branch
- [ ] Explore the code
    - [ ] set up a development environment for c++ on your computer - see the __Cherno Playlist__ first few videos for help
    - [ ] try to figure out what's going on in the _components_ and _game_ subfolders
    - [ ] find out what a preprocessor, compiler and linker do - see the __Cherno Playlist__ first few videos for help
    - [ ] check out the _CMakeLists.txt_ and _build-and-run.sh_ files and the created _build_ folder and try to understand how they lead to the application going from code to executable
- [ ] Change to branch __lessons__
- [ ] Move to LESSONS.md for further tasks
