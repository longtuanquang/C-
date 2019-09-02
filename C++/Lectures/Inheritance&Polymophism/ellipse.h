#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include "shape.h"
class Ellipse: public Shape{
protected:
    double major_radius;
    double minor_radius;
public:
    Ellipse(double major, double minor): major_radius(major), minor_radius(minor){}
    double span() const override;
    double area() const override;
};

#endif