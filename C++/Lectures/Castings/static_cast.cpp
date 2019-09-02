#include <iostream> 
using namespace std; 
class Base{
};
class Derirved: private Base{ // it should be public 

};


int main() 
{ 
    float f = 3.5; 
    int a = f; // this is how you do in C 
    int b = static_cast<int>(f); 
    cout << "a is: " << a << " b is: " << b; 


    //Casting Inheritance
    Derirved d1;
    Base* b1 = (Base*)(&d1); // allowed
    Base* b2 = static_cast<Base*> (&d1);
    return 0;
} 