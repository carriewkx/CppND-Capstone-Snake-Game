# CPPND: Capstone Snake Game - Carrie

This is a carrie's capstone repo for the Capstone project in the [Udacity C++ Nanodegree Program](https://www.udacity.com/course/c-plus-plus-nanodegree--nd213). The code for this repo is based by [this](https://codereview.stackexchange.com/questions/212296/snake-game-in-c-with-sdl) 


## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* SDL2 >= 2.0
  * All installation instructions can be found [here](https://wiki.libsdl.org/Installation)
  >Note that for Linux, an `apt` or `apt-get` installation is preferred to building from source. 
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)

## Instruction for running locally
1. Clone this repo.
2. Make a build directory in the top level directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./SnakeGame`.

## How to play && Expected bahaviour 
* on terminal, ./SnakeGame
* pick a difficulty (input either 1 or 2 or 3)
* Tab space bar (or any key) to start
* use up/down/left/right control the snake to grow by eating the apple
* If game failed, end screen will show up, can tab again to restart

## Project Structure

* main.cpp: The main function of the project, where the window gets rendered and game gets run 
* controller: class for user control (this came with the original project)
* game: Code for running the game itself (came with the project)
* helper: Helper contains function to read difficulty level input and pass it back to main.cpp
* playrenderer: this is the original project - renderer class, replaced here with playrenderer and inherits from renderer
* renderer: an interface for screen rendering 
* snake: snake object, contains all information about snake (speed, size etc) (came with the original project)
* staticrenderer: contains start game and end game screen. This also inherits from interface renderer


## Rubrics Points
1. The project demonstrates an understanding of C++ functions and control structures.: see staticrenderer.cpp or helper.cpp
2. The project reads data from a file and process the data, or the program writes data to a file.: see playrenderer.cpp line 25 (reading apple image as food)
3. The project accepts user input and processes the input.: see helper.cpp line 9 (reading difficulty level choice from user)
4. The project uses Object Oriented Programming techniques. see helper.h, renderer.h and staticrenderer.h (they are organized into claaes)
5. Classes use appropriate access specifiers for class members. See renderer.h line 21 22. there are public and protected memebers
6. Classes abstract implementation details from their interfaces. see renderer.h and staticrenderer.h and playrenderer.h. renderer.h is abtract class where staticrenderer and playrenderer have the actual function implementations.
7. The project makes use of references in function declarations.: see helper.cpp line 6 and staticrenderer.h line 16



## reference

apple image: 
https://www.models-resource.com/nintendo_switch/animalcrossingnewhorizons/model/35108/

## CC Attribution-ShareAlike 4.0 International


Shield: [![CC BY-SA 4.0][cc-by-sa-shield]][cc-by-sa]

This work is licensed under a
[Creative Commons Attribution-ShareAlike 4.0 International License][cc-by-sa].

[![CC BY-SA 4.0][cc-by-sa-image]][cc-by-sa]

[cc-by-sa]: http://creativecommons.org/licenses/by-sa/4.0/
[cc-by-sa-image]: https://licensebuttons.net/l/by-sa/4.0/88x31.png
[cc-by-sa-shield]: https://img.shields.io/badge/License-CC%20BY--SA%204.0-lightgrey.svg
