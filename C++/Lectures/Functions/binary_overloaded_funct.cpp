#include <iostream>
using namespace std;

class Distance{
public:
    int feet;
    int inches;
    Distance(){
        this->feet = 0;
        this->inches = 0;
    }
    Distance(int f, int i){
        this->feet = f;
        this->inches = i;
    }
    // Overloaded operator (+): return a new Distance with 
    // total feet and total inches of two objects of Distances
    Distance operator+(Distance& d2) { // call by references{
        Distance d3;
        d3.feet = this->feet + d2.feet;
        d3.inches = this->inches + d2.inches;
        return d3;

    }
};
// Driver Code 
int main() 
{ 
    // Declaring and Initializing first object 
    Distance d1(8, 9); 
  
    // Declaring and Initializing second object 
    Distance d2(10, 2); 
  
    // Declaring third object 
    Distance d3; 
  
    // Use overloaded operator 
    d3 = d1 + d2; 
  
    // Display the result 
    cout << "\nTotal Feet & Inches: " << d3.feet << "'" << d3.inches; 
    return 0; 
} 