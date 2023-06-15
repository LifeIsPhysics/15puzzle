//
// Created by berke on 6/15/23.
//

#ifndef INC_15PUZZLE_TILE_H
#define INC_15PUZZLE_TILE_H

#include <iostream>

class Tile {
public:
    explicit Tile(int num=0): mNum{num}{}

    int getNum() const{
        return mNum;
    }

    bool isEmpty() const {
        return mNum==0;
    }

    friend std::ostream& operator<< (std::ostream& out, Tile tile);

private:
    int mNum{};
};


#endif //INC_15PUZZLE_TILE_H
