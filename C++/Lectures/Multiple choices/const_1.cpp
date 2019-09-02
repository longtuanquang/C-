#include <iostream>
using namespace std;
class Test 
{
  
  public:
  int x;
  Test() { x = 5;}
};

int main(){
    /*
    const char* p = "12345";
    cout << "before assgined *p is: " << *p << endl;
    //char* f = "KMPQ";
    p = "KMPQ";
    cout << *p; 
    
    
    const char** q = &p;
    cout << "*q is 12345 right?: " << *q << endl;
    *q = "abcde";
    const char *s = ++p;
    p = "XYZWVU";

    cout << *++s << endl;
    cout << "p is " << p << endl;
    cout << "*p is now: " << *p << endl;
    cout << "*s is " << *s << endl;
    const int i = 10;
     */
    Test *t = new Test();
    cout << t->x;

   

    return 0;

}