#include<iostream>
using namespace std;
 
class Point {

public:
    int x, y;
    Point(){};
    Point(int x, int y): x(x), y(y) { cout << "Normal Constructor called" << endl; }
    Point(const Point &t) { cout << "Copy constructor called " << endl; }
    void print(){
        cout << "x is :" << x << ", y is: " << y << endl;
    }
};
 
int main()
{
   Point *t1, *t2;
   t1 = new Point(10,5 );
   t2 = new Point(*t1);
   Point t3 = *t1;
   Point t4;
   //t4 = &t3;
   t4 = t3;
   t1->print();
   t2->print();
   t3.print();
   t4.print();


   return 0;
}