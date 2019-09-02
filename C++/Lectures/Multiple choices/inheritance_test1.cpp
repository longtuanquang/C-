#include <iostream>
using namespace std;

class A{
    int x;
};

class B: public A{
    public:
        void show(){
            x = 10; // member x of Base class is inassessble!
            cout << x;
        }
};

int main(){
    B b;
    b.show();
    return 0;
}