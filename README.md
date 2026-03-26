# 🏒 AirHockey2D

A 2-player Air Hockey game built in C++ with the SGG graphics framework.
This project focuses on real-time game logic, collision detection, scoring, and object-oriented design.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Features

* 2-player local gameplay
* Real-time puck movement and collision handling
* Goal detection and score tracking
* Game state management
* End-game screen when a player reaches 5 points

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Controls

### Player 1

* `W` → Up
* `S` → Down
* `A` → Left
* `D` → Right

### Player 2

* `↑` → Up
* `↓` → Down
* `←` → Left
* `→` → Right

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Tech Stack

* C++
* Visual Studio
* SGG Graphics Library

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Project Structure


AirHockey2D/
│
├── include/
│   └── sgg/
│       ├── graphics.h
│       └── scancodes.h
│
├── lib/
│   ├── sgg.lib
│   └── sggd.lib
│
├── bin/
│   ├── assets/
│   ├── SDL2.dll
│   ├── SDL2_mixer.dll
│   ├── freetype.dll
│   └── other required runtime DLL files
│
├── Ball.cpp
├── Ball.h
├── GameObject.cpp
├── GameObject.h
├── GameState.cpp
├── GameState.h
├── Goal.cpp
├── Goal.h
├── Level.cpp
├── Level.h
├── Player.cpp
├── Player.h
├── box.h
├── util.h
├── main.cpp
├── Project1.sln
└── README.md


--------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Requirements

Before building the project, make sure the SGG framework is set up manually.

You need:

* SGG header files inside `include/sgg/`
* SGG library files inside `lib/`
* Required runtime `.dll` files inside `bin/`

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Setup Instructions

### 1. Header files

Place the SGG header files in:


include/sgg/

Example:

* `graphics.h`
* `scancodes.h`

### 2. Library files

Create a folder named:

lib/

Place the SGG library files there:

* `sgg.lib`
* `sggd.lib`

### 3. Runtime DLL files

Place all required runtime `.dll` files in:

bin/

Examples may include:

* `SDL2.dll`
* `SDL2_mixer.dll`
* `freetype.dll`


### 4. SGG main/source file

If your SGG setup includes an additional source file such as an SGG main file, add it to the Visual Studio project as required by your framework setup.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Visual Studio Configuration

Open `Project1.sln` in Visual Studio and make sure the project is configured correctly.

### Include Directories

Add:

include/

### Library Directories

Add:

lib/

### Working Directory

Set the working directory to:

$(ProjectDir)bin

This is necessary so the game can correctly find:

assets\

and the required `.dll` files at runtime.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Build and Run

1. Open `Project1.sln` in Visual Studio
2. Build the solution with `Ctrl + Shift + B`
3. Run the project with `F5`

If everything is configured correctly, the game should launch normally.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Notes

* This repository does not include external SGG/SDL binaries by default.
* The required framework files should be added locally as described above.
* This project was developed for educational purposes and uses an external graphics framework.

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Future Improvements

* Add sound effects and background music
* Add AI opponent
* Add pause and restart menu
* Improve collision and puck physics
* Refactor project structure into `src/` and `include/`

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

## Author

Spyrou Agamemnon-Ioannis

--------------------------------------------------------------------------------------------------------------------------------------------------------------------

## License

This project is for educational and portfolio use.
