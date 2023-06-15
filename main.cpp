/*
Board things:

    * Display the game board
    * Display an individual tile
    * Randomize the starting state
    * Slide tiles
    * Determine if win condition reached

User things:

    * Get commands from user
    * Handle invalid input
    * Allow the user to quit before winning
*/

#include "direction.h"
#include "board.h"
#include "tile.h"
#include "Point.h"
#include <numeric>
#include <iostream>


namespace UserInput{
    bool isValidInput(char c){
        return c == 'w'
            || c == 'a'
            || c == 's'
            || c == 'd'
            || c == 'q';
    }

    void ignoreLine(){
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    char getCharacter(){
        char cmd{};
        std::cin >> cmd;
        ignoreLine(); //remove any extraneous input
        return cmd;
    }

    char getCommandFromUser(){
        char c{};

        while (!isValidInput(c))
            c = getCharacter();

        return c;
    }

    Direction charToDirection(char c){
        switch(c){
            case 'w': return Direction{ Direction::up };
            case 'a': return Direction{ Direction::left };
            case 's': return Direction{ Direction::down };
            case 'd': return Direction{ Direction::right };
        }
        assert(0 && "Unsupported direction was passed!");
        return Direction{ Direction::up };
    }

}

int main()
{
    Board board{};
    board.randomizePuzzle();
    std::cout << board;

    std::cout << "Enter a command: ";
    while (!board.playerWon())
    {
        char ch{ UserInput::getCommandFromUser() };

        // Handle non-direction commands
        if (ch == 'q')
        {
            std::cout << "\n\nBye!\n\n";
            return 0;
        }

        // Handle direction commands
        Direction dir{ UserInput::charToDirection(ch) };

        bool userMoved { board.moveTile(dir) };
        if (userMoved)
            std::cout << board;
    }
    std::cout << "\n\nYou won!\n\n";

    return 0;
}