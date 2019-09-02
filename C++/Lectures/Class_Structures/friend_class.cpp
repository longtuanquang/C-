#include <iostream>
using namespace std;

// Declare class B to be a friend of class A
// B can access private & protected members of A
class A{
private:
    int a;
public:
    A(){
        a = 10;
    }
    friend class B;
};


class B{
private:
    int b;
public:
    void show(A& a){
        cout << "A::a is: " << a.a << endl;
    }
};

int main(){
    A a;
    B b;
    b.show(a);
    return 0;
}