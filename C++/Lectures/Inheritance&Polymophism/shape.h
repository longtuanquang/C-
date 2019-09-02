#ifndef SHAPE_H_
#define SHAPE_H_
/*
 *Shape is a base class of all shapes 
 */
class Shape{
public:
    // Longgest distance accross the shape
    // pure virtual function providing interface work
    virtual double span() const = 0;
    // The shape's area
    virtual double area() const = 0;
};
#endif