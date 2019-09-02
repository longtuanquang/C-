#ifndef SQUARE_H_
#define SQUARE_H_
#include "rectangle.h"
// A square is a special case of a rectangle

class Square: public Rectangle {
public:
    Square(double side);
    // inherited methods work as is=> no need to change behavior
};

#endif