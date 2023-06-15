//
// Created by berke on 6/15/23.
//

#ifndef INC_15PUZZLE_POINT_H
#define INC_15PUZZLE_POINT_H

#include "direction.h"

class Point {
public:
    Point(int x=0, int y=0): mX{ x }, mY{ y }{}

    int getX() const{ return mX; }
    int getY() const{ return mY; }

    friend bool operator== (const Point& p1, const Point& p2);
    friend bool operator!= (const Point& p1, const Point& p2);

    Point getAdjacentPoint(Direction dir) const{
        switch(dir.getType()){
            case Direction::up : return Point{ mX, mY - 1};
            case Direction::down : return Point{ mX, mY + 1};
            case Direction::left : return Point{ mX - 1, mY };
            case Direction::right : return Point{ mX + 1, mY};
        }
        return *this;
    }

    friend std::ostream& operator<< (std::ostream& out, const Point& p);


private:
    int mX{}, mY{};
};


#endif //INC_15PUZZLE_POINT_H
