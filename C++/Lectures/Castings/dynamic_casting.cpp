#include <iostream> 
#include "string.h"
using namespace std; 

class Base {
    protected:
        int m_value;
    public:
        Base(int val){
            m_value = val;
        }
        virtual ~Base(){ cout << "Destroyed object Base" << endl;}
};
class Derived: public Base {
    protected: 
        string name;

    public: 
        Derived(int val, string s): Base(val),name(s){}
        const string& getName(){
            return name;
        }     
};
// OUTSIDE FUNCTION:
Base* getObjects(bool bReturnDerived){
    if(bReturnDerived)
        return new Derived(1, "Apple");
    else
    {
        return new Base(2);
    }
}
int main(){
    Base* b = getObjects(false);
    // TO DO: print the name of Derived object, having Base pointer
    // USE: dynamic casting for converting base class pointers to 
    // derived class pointer. This is called DOWNCASTING
    Derived* d = dynamic_cast<Derived*>(b);
    if(d){
         cout << "Name of Derived is: " << d->getName() << endl;
    } else{
        cout << " We dont need cast because it's Base object!";
    }
   

    delete b;
    return 0;
    }