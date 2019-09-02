#ifndef TRIANGLE_H_
#define TRIANGLE_H_
// guard file triangle
#include "shape.h"

class Triangle: public Shape{
protected:
    double side1;
    double side2;
    double side3;
public:
    // construction
    Triangle(double s1, double s2, double s3);
    double span() const override;
    double area() const override;
};

#endif
