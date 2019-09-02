#include <iostream> 
#include "string.h"
using namespace std; 
// class Identifier
enum classID{
    BASE,
    DERIVED
};
class Base {
    protected:
        int m_value;
    public:
        Base(int val){
            m_value = val;
        }
        virtual ~Base(){ cout << "Destroyed object Base" << endl;}
        virtual classID getClassID() {return BASE;}
};
class Derived: public Base {
    protected: 
        string name;

    public: 
        Derived(int val, string s): Base(val),name(s){}
        const string& getName(){
            return name;
        }   
        virtual classID getClassID() {return DERIVED;}
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
    Base* b = getObjects(true);
    // TO DO: print the name of Derived object, having Base pointer
    // USE: dynamic casting for converting base class pointers to 
    // derived class pointer. This is called DOWNCASTING
    if(b->getClassID() == DERIVED){
        Derived* d = static_cast<Derived*>(b);
        cout << "Name of Derived is: " << d->getName() << endl;
    }
    delete b;
    return 0;
    }