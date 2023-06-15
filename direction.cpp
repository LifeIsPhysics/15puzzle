//
// Created by berke on 6/15/23.
//

#include "direction.h"

std::ostream& operator<< (std::ostream& out, Direction direction){
    switch(direction.getType()){
        case Direction::up :     return (out << "up");
        case Direction::down :   return (out << "down");
        case Direction::left :   return (out << "left");
        case Direction::right :  return (out << "right");
        default:
            return (out << "Unknown direction");
    }
}
