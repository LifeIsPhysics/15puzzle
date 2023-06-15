//
// Created by berke on 6/15/23.
//

#include "board.h"

void printEmptyLines(int lines) {
    for(int i{0}; i < lines; ++i){
        std::cout << '\n';
    }
}

std::ostream& operator<< (std::ostream& out, const Board& board){
    printEmptyLines(g_consoleLines);

    for(int row{0}; row < Board::TILE_SIZE; ++row){
        for(int col{0}; col < Board::TILE_SIZE; ++col){
            out << board.mTiles[row][col] << ' ';
        }
        out << '\n';
    }
}

bool operator==(const Board& f1, const Board& f2)
{
    for (int y = 0; y < Board::TILE_SIZE; ++y)
        for (int x = 0; x < Board::TILE_SIZE; ++x)
            if (f1.mTiles[y][x].getNum() != f2.mTiles[y][x].getNum())
                return false;

    return true;
}
