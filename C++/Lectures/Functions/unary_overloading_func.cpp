#include <iostream>
using namespace std;

class Distance{
public:
    int feet;
    int inches;
    Distance(int f, int i){
        feet = f;
        inches = i;
    }

    // Overloading operator '-'
    void operator-(){
        feet--;
        inches--;
        cout << "Feet & Inches are decremented!: " << feet << "'" << inches << endl;
    }

};

int main(){
    Distance d1(5,8);
    -d1;
    return 0;
}