# Sudoku Game – C++ / SFML Desktop App

A Sudoku game written in **C++**, originally developed as a terminal-based project and currently being upgraded into a full graphical desktop application using **SFML**.

The project began as a way to dynamically learn core C++ concepts such as pointers, functions, file handling, validation, and game logic. After completing the console version, I decided to expand it into a GUI application and use the project to learn event-driven programming, graphical interfaces, and SFML.

## Current Status

🚧 **Work in Progress**

The original console version of the Sudoku game is functional.

The project is currently being redesigned with an **SFML graphical interface**, including:

- Game windows and menus
- Mouse interaction
- Buttons
- Dynamic text
- Sudoku grid rendering
- Graphical number input
- Game-state displays

The final goal is to move all gameplay from the terminal into the SFML interface.

## Features

The Sudoku game logic includes:

- 9×9 Sudoku board
- Puzzle generation
- Sudoku solver
- Difficulty selection
- Input validation
- Detection of incorrect moves
- Locked/pre-filled cells
- Hint system
- Limited lives
- Score system
- Game timer
- Win/loss detection
- Replay functionality

Some of these features currently exist in the console version and are gradually being integrated into the graphical version.

## Built With

- **C++**
- **SFML**
- **Visual Studio Code**
- **MSYS2 / MinGW-w64**

## Project Structure

The project is being separated into components so that the Sudoku game logic and graphical interface can be developed independently.

The separation goes as follow:

```text
C++_Sudoku_Game-SFML_Desktop_App/
│
├── Assets/
│   └── Fonts/
│
├── SFML_code_trials/
│   └── Experimental SFML programs
│
├── Game_Files
│   └── SudokuBoard.hpp
│   └── SudokuBoard.cpp
│   │
│   └── SudokuGame.hpp
│   └── SudokuGame.cpp
│   |
│   └── SudokuWindow.hpp
│   └── SudokuWindow.cpp
|   |
│   └── MainPlay.cpp
│
└── Notes.md
