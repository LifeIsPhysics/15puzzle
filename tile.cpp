//
// Created by berke on 6/15/23.
//

#include "tile.h"


std::ostream& operator<< (std::ostream& out, Tile tile) {
    if(tile.mNum > 9)
        out << " " << tile.getNum() << " ";
    else if(tile.getNum() > 0)
        out << "  " << tile.getNum() << " ";
    else
        out << "    ";
    return out;
}

