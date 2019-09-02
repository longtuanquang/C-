#include "rectangle.h"
#include <algorithm> // for max function

// Generally for rectangles
Rectangle::Rectangle(double len, double wid):length(len), width(wid){}

// Lenght of the longer side--determine which is longer
double Rectangle::span() const {
    return std::max(length,width);
}
double Rectangle::area() const{
    return length * width;
}
