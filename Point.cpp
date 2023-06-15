//
// Created by berke on 6/15/23.
//

#include "Point.h"


std::ostream& operator<< (std::ostream& out, const Point& p){
    out << "Point(" << p.mX << ", " << p.mY << ')';
    return out;
}

bool operator!= (const Point& p1, const Point& p2) {
    return !(p1==p2);
}
bool operator== (const Point& p1, const Point& p2) {
    return (p1.mX == p2.mX && p1.mY == p2.mY);
}