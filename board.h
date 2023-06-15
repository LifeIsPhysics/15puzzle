//
// Created by berke on 6/15/23.
//

#ifndef INC_15PUZZLE_BOARD_H
#define INC_15PUZZLE_BOARD_H

#include "Point.h"
#include "tile.h"
#include <iostream>

// Increase amount of new lines if your board isn't
// at the very bottom of the console
constexpr int g_consoleLines{ 25 };


class Board {
public:
    Board()=default;

    friend void printEmptyLines(int lines);
    friend std::ostream& operator<< (std::ostream& out, const Board& board);
    friend bool operator==(const Board& f1, const Board& f2);

    Point getEmptyTilePos() const{
        for(int y{0}; y < TILE_SIZE; ++y)
            for(int x{0}; x < TILE_SIZE; ++x){
                if( mTiles[y][x].isEmpty() )
                    return Point{x, y};
            }
        assert(0 && "There is no empty tile in the board!!!");
        return Point{-1, -1};
    }

    void swapTiles(Point p1, Point p2){
        std::swap(mTiles[p1.getY()][p1.getX()],
                  mTiles[p2.getY()][p2.getX()]);
    }
    void randomizePuzzle(){
        for(int i{0}; i<=2; ++i){
            Point p0Tile{ getEmptyTilePos() };
            Point pAdj{};
            do{
                pAdj = p0Tile.getAdjacentPoint(Direction::getRandomDirection());
            }while(!isValidTilePos(pAdj));

            swapTiles(p0Tile, pAdj);
        }
    }

    bool moveTile(Direction dir){
        Point emptyTile{ getEmptyTilePos() };
        Point adj{ emptyTile.getAdjacentPoint(-dir) };

        if(!isValidTilePos(adj)){
            return false;
        }

        swapTiles(adj, emptyTile);
        return true;
    }
    bool playerWon() const
    {
        static Board s_solved{};  // generate a solved board
        return s_solved == *this; // player wins if current board == solved board
    }
    static bool isValidTilePos(Point p){
        return (0 <= p.getX() && p.getX() < TILE_SIZE)
               && (0 <= p.getY() && p.getY() < TILE_SIZE);
    }

private:
    static constexpr int TILE_SIZE{4};

    Tile mTiles[TILE_SIZE][TILE_SIZE] {
        {Tile{ 1 }, Tile{ 2 }, Tile{ 3 }, Tile{ 4 }},
        {Tile{ 5 }, Tile{ 6 }, Tile{ 7 }, Tile{ 8 }},
        {Tile{ 9 }, Tile{ 10 }, Tile{ 11 }, Tile{ 12 }},
        {Tile{ 13 }, Tile{ 14 }, Tile{ 15 }, Tile{ 0 }}
    };
};


#endif //INC_15PUZZLE_BOARD_H
