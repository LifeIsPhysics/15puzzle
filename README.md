# 15puzzle

Terminal based game of 15 puzzle.

Wikipedia: https://en.wikipedia.org/wiki/15_puzzle  
Web based game version (not affiliated): https://15puzzle.netlify.app/

# Usage

Only a recent C++ compiler and CMake is needed to build this project on your computer.  
Using arch's package manager pacman type this command into your terminal
```bash
    sudo pacman -S gcc cmake
```
To build this project type this command into your terminal
```bash
mkdir build
cd build
cmake ..
make
```
If you want to play a game of 15 puzzle in your terminal type this command into your  
terminal
```bash
./15puzzle
```
You move the tile with the input wasd and then pressing the enter key.

# Example output
Once you've won you will be congratulated with the message on the bottom.
```bash
    1    2    3    4
    5    6    7    8
    9   10   11   12
   13   14   15
Enter a command:

You won!
```
