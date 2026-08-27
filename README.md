# 🔵 Abalone Game

A console-based implementation of the classic **Abalone strategy board game**, developed in **C++**.

The game supports two local players, hexagonal board movement, group moves, pushing opponent pieces, score tracking, and Save/Continue functionality.

## 🎮 About the Game

Abalone is a two-player abstract strategy game played with black and white marbles on a hexagonal board.

Each player starts with **14 marbles**.

The objective is to:

> **Push 6 of your opponent's marbles off the board.**

The first player to reduce the opponent to 8 remaining marbles wins.

## ✨ Features

* Two-player local gameplay
* Hexagonal Abalone board
* 14 marbles per player
* Move 1, 2, or 3 marbles
* Six movement directions
* Opponent pushing mechanics
* Turn-based gameplay
* Player name support
* Save and Continue
* Scoreboard
* Built-in game guide
* Colored Windows console
* Precompiled executables included

## 🧩 Board Structure

The board contains **9 rows** with the following number of playable positions:

```text
5 6 7 8 9 8 7 6 5
```

Internally:

```cpp
const int rows = 9;

int* columns = new int[rows] {
    5, 6, 7, 8, 9, 8, 7, 6, 5
};
```

The board uses:

```text
x = Player 1
o = Player 2
# = Empty position
```

## 🎯 Movement

A player can move:

```text
1 marble
2 marbles
3 marbles
```

at a time.

The selected marbles must form a valid line.

The six supported directions are:

| Key | Direction  |
| --- | ---------- |
| `Q` | Up Left    |
| `E` | Up Right   |
| `D` | Right      |
| `C` | Down Right |
| `Z` | Down Left  |
| `A` | Left       |

Example:

```text
Coordinate 1: 2 2
Coordinate 2: 2 3
Coordinate 3: 2 4
Direction: D
```

Coordinates are entered using:

```text
Row Column
```

## ⚔️ Pushing

The game implements the main Abalone pushing mechanic.

A stronger line of marbles can push a smaller opposing line when the movement direction and board position allow it.

Typical situations include:

```text
2 vs 1 → Push
3 vs 1 → Push
3 vs 2 → Push
```

A group cannot push an equal or larger opposing group.

Marbles can eventually be pushed beyond the edge of the board.

## 🏆 Win Condition

Each player begins with:

```text
14 marbles
```

The game ends when one player has only:

```text
8 marbles
```

remaining.

That means the opponent has successfully pushed **6 marbles off the board**.

The winner and both players' scores are then displayed.

## 📊 Scoreboard

The game calculates and stores player scores in:

```text
score.txt
```

The main menu provides a dedicated:

```text
ScoreBoard
```

option for viewing saved scores.

## 💾 Save & Continue

The current match can be saved and restored later.

The game uses:

```text
save.txt
saveName.txt
savePlayer.txt
score.txt
```

### `save.txt`

Stores the current board.

### `saveName.txt`

Stores both player names.

### `savePlayer.txt`

Stores turn/player information.

### `score.txt`

Stores the calculated scores.

## 🖥️ Main Menu

When the application starts:

```text
======ABALONE======

[0] Start
[1] Continue
[2] ScoreBoard
[3] How to play?
[4] Exit
```

### Start

Creates a new board and asks for both player names.

### Continue

Loads the previously saved board and player information.

### ScoreBoard

Displays stored scores.

### How to Play

Shows movement controls and coordinate instructions.

### Exit

Closes the application.

## 📂 Project Structure

```text
AbaloneGame/
│
├── c++_AbaloneGame/
│   │
│   ├── Abalone_last_edition.cpp
│   │
│   └── output/
│       ├── Abalone_last_edition.exe
│       ├── BPProject5_AmirMohammadHemmati_1402012268020.exe
│       ├── project.exe
│       ├── save.txt
│       ├── saveName.txt
│       ├── savePlayer.txt
│       └── score.txt
│
└── README.md
```

## 🛠️ Technologies

* C++
* Dynamic arrays
* Structs
* File I/O
* Console input/output
* Game-state management
* Windows Console API

The source currently uses:

```cpp
#include <conio.h>
#include <windows.h>
```

so the current version is primarily designed for **Windows**.

## 🚀 Installation

Clone the repository:

```bash
git clone https://github.com/parhamhmtt/AbaloneGame.git
```

Enter the project:

```bash
cd AbaloneGame
```

## ▶️ Run

A precompiled executable is available at:

```text
c++_AbaloneGame/output/Abalone_last_edition.exe
```

On Windows PowerShell:

```powershell
.\c++_AbaloneGame\output\Abalone_last_edition.exe
```

## 🔨 Build from Source

Using MinGW `g++` on Windows:

```bash
g++ "c++_AbaloneGame/Abalone_last_edition.cpp" -o "c++_AbaloneGame/output/Abalone.exe"
```

Then run:

```powershell
.\c++_AbaloneGame\output\Abalone.exe
```

## 🔄 Game Flow

```text
Start
  ↓
Enter Player Names
  ↓
Display Board
  ↓
Select 1–3 Marbles
  ↓
Choose Direction
  ↓
Validate Move
  ↓
Move / Push
  ↓
Save Game
  ↓
Calculate Score
  ↓
Switch Player
  ↓
6 Opponent Marbles Removed
  ↓
Winner
```

## ⚠️ Current Limitations

* Console-only interface
* Windows-specific headers
* Two local players only
* No AI opponent
* No online multiplayer
* Text-based coordinate input
* Save files use plain text
* No automated tests
* Most game logic is contained in one large source file

## 🚧 Possible Improvements

* Graphical user interface
* AI opponent
* Online multiplayer
* Cross-platform support
* Improved input validation
* Undo/redo support
* Match history
* Difficulty levels
* Automated tests
* Refactor game logic into multiple classes/files

## 👨‍💻 Repository

**AbaloneGame**

C++ • Console Game • Strategy • Two Player • Abalone

![Abalone_standard svg](https://github.com/user-attachments/assets/2ee46932-9b0e-43e8-92c9-7ef2dffc3290)
