# Notes to self in order to create a full Sudoku application
Building an entire Sudoku game will take time, so
Minimum Requirements:
- Build a Sudoku board and puzzle generator

- Display the board in the console.

Let the player:
- Enter a row, column, and number.

- Reject moves into fixed (original) cells.

- Check whether the move follows Sudoku rules (row, column, and subgrid).

- Update the board if the move is valid.

- End the game when the board is completely filled.

Extra Goals (Optional): 
- Difficulty selection (different predefined boards) `(DONE!!)`

- A hint system `(DONE)`

- Save/load the game `(... Not yet.)`

- A timer `(DONE!!)`

- Limited lives (e.g., lose after 3 invalid moves) `(DONE!!)`

- Score based on time or mistakes `(DONE!!)`

## AKB's notes:
On a rough, unpolished basis, every program should be as follow:

**1- `SudokuBoard.hpp`**
Defines the `board class` interface: size, grid storage, getting/setting values, checking whether a move is legal, printing the board, clearing editable cells, etc.

**2- `SudokuBoard.cpp`**
Implements the board logic. This is where the 9x9 grid lives and where Sudoku rules are checked: row, column, and 3x3 box validation.

   - `(Go to MainPlay.cpp to run a quick test to ensure the board is working)`

**3- `SudokuGame.hpp`**
Defines the game controller: starting the game, reading user input, checking win/loss state, managing turns, maybe tracking mistakes.

**4- `SudokuGame.cpp`**
Implements the gameplay loop. This is where we ask the user for row/col/value, call the board to validate the move, update the board, and refresh the screen.

**5- `SudokuWindow.hpp`**
Defines the window screen class and declares all the functions necessary for the program to be displayed on an actual, interactive environment.

**6- `SudokuWindow.cpp`**
Defines the functions that were created in the .hpp file so that they can actually be used by Play.cpp.

**5- `Play.cpp`**
Very small. It should just create a `SudokuGame object` and start it.

`Example:`
```Text:
    #include "SudokuGame.hpp"

    int main() {
        SudokuGame game;
        game.start();
        return 0;
    }
```

## List of edge cases and things to fix (on the terminal side): 
- ClearScreen works, but it erases way too much. It's erasing welcoming message before user can even read it.
  Also, user doesn't receive any form of confirmation that their move was correct. 
  Likewise, user can't see the warning messages of invalid move or to not change locked cells 
  ```(although the cells do stay unchanged, so we can confirm that works. Sweet!!)```

- Sudoku Board could look cleaner by adding lines to at least separate each subgrid and border the whole board.

- Empty cells should appear as empty spaces, not 0 `(However, behind courtains, program should still see them as 0s).`

- Obvious edge case: If user enters a letter or word, the program enters an infinite loop

- Sudoku solved puzzle still needs to be printed in a .txt file so that I don't have to solve each Sudoku by myself... 
  `(Actually, let's turn this into a feature for the user too. Instead of not allowing the user to see the .txt file, `
  `let them see the fixed solution once they've lost the game. `
  `This needs to be added alongside the limited lives extra feature tho, so we can worry about that later)`

- Would be nice to mark a way to distinguish which numbers were placed by user and which numbers were already there.

- If user enters an invalid row `(out of 1 to 9 range)`, the program allows them to continue despite the invalid row and 
  never informs them about the invalid row placement. At least the board doesn't modifies a non-existant value, but still, 
  a message should stop the user from entering the columns if their rows are bad `(and viceversa)`.

## Things to fix and handle (On the SFML and render side):
**Great deal of the visual features for this app will be inspired by Sudoku.com and their phone application**

- Obvious part `(and probably the last to be solved)` is that the window needs to look better. 
  Improve welcoming, make home-screen more appealing, user-friendly, etc.

- Missing: A play button `(Eventually have to become into "new game" and "continue game" buttons)`.

- Missing: A settings button.

- Missing: A settings screen that let the user customize the sounds and visuals of the game. 
  Should also allow the user to remove stuff like hints or change the amount of mistakes possibles.

- Missing: A game screen that shows the Sudoku game features, the grid, the puzzle of missing numbers, the hints, mistakes, score, time.

- Missing: A difficult screen that lets the user decide how hard the game should be before playing it `(Easy, normal or hard)`.

- Additional feature: Add a numerical keyboard on the game screen so that the user can input numbers with it rather than using their physical keyboard
  `(This could be useful for people who don't have, for whatever reason, a physical keyboard, or want to use solely a mouse to play... `
  `Dunno why you'd do that actually, but hey, my job is to make the game as accessible as possible, not me telling you how you should play it.)`

- Add code so that the mouse can interact with the buttons and change from screen to screen. In addition, the mouse needs to interact with the grid in order to select a cell.

- Additional feature: If the user clicks on a number that is on the grid, the screen should highlight all cells where the number is repeated.
  In a similar fashion, when the user presses a cell, the game should also slightly shade the box, row and column where that cell belongs.

## Command to put in the terminal
**Linker:**
g++ -std=c++17 MainPlay.cpp SudokuBoard.cpp SudokuGame.cpp SudokuWindow.cpp -o SudokuGame -lsfml-graphics -lsfml-window -lsfml-system

**Executable:**
.\SudokuGame.exe
