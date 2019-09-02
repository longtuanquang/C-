#include <iostream> 
#include <cmath>
using namespace std;
class Vector{
    public:
        Vector(){}
        Vector(float X, float Y){
            x = X;
            y = Y;
        }
        float Length() const;
        float LengthSquare() const;
        Vector operator+(const Vector& v) const;
        Vector operator-(const Vector& v) const;

        Vector operator*(float s) const;
        Vector operator/(float s) const;
        Vector Normalized() const;
        float x, y;

};
class Point{
    float x, y;
    Point addVector(Vector v);
};
Point Point::addVector(Vector v){
    Point p2;
    p2.x = x + v.x;
    p2.y = y + v.y;
    return p2;
}

float Vector::Length() const {
    return sqrt(x*x + y*y);
}
float Vector::LengthSquare()const {
    return (x*x + y*y);
}
// Implement Vector adding
Vector Vector::operator+(const Vector& v) const{
    Vector final_vector;
    final_vector.x = (*this).x + v.x;
    final_vector.y = (*this).y + v.y;
    return final_vector;
}
// Implement Vector adding
Vector Vector::operator-(const Vector& v) const{
    return Vector(x - v.x, y - v.y);
}

// Implement Vector scaling function
Vector Vector::operator*(float s) const{
    Vector scale;
    scale.x = x*s;
    scale.y = y*s;
    return scale;
}
// Implement Vector scaling function
Vector Vector::operator/(float s) const{
    Vector scale;
    scale.x = (float)x/s;
    scale.y = (float)y/s;
    return scale;
}
Vector Vector::Normalized() const{
    Vector normalized;
    normalized = (*this) / Length();
    return normalized;
}
float dot_product(const Vector &a, const Vector &b){
    return a.x*b.x + a.y*b.y;
}
int main(){
    Vector v1(3,4);
    Vector doubled;
    doubled = v1* 2;
    Vector normalized;
    normalized = v1.Normalized();
    cout << "Pacman doubled speed :" << doubled.Length() << "\n";
    cout << "Pacman normalized vector's length :" << normalized.Length() << "\n";

    // Test adding two vectors
    Vector v2(5,8);
    Vector sum;
    sum = v1+v2;
    cout << "Sum vector is :" << sum.Length() << "\n";


    return 0;
}