//
// Created by berke on 6/15/23.
//

#ifndef INC_15PUZZLE_DIRECTION_H
#define INC_15PUZZLE_DIRECTION_H

#include "Random.h"
#include <iostream>
#include <string_view>
#include <cassert>

class Direction {
public:
    enum Type{
        up,
        down,
        left,
        right,

        max_directions
    };

    Direction(Type type): mType{type}{}

    Type getType() const{ return mType; }

    Direction operator- () const{
        switch(mType){
            case up:    return Direction{ down };
            case down:  return Direction{ up };
            case left:  return Direction{ right };
            case right: return Direction{ left };
            //case max_directions:
            //    break;
        }

        assert(0 && "Unsupported direction was passed");
        return Direction{ up };
    }

    friend std::ostream& operator<< (std::ostream& out, Direction direction);

    static Type getRandomDirection(){
        return static_cast<Type>( Random::get(0, Type::max_directions - 1) );
    }

private:
    Type mType{};
};


#endif //INC_15PUZZLE_DIRECTION_H
