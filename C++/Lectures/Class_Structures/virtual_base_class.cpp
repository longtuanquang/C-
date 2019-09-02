#include <iostream> 
using namespace std; 
class A
{
public:
	int a;
	A()// constructor
	{
		a = 10;
	}
};

// class A is inhereted from B and C
class B :public virtual A{

};
class C : public virtual A{

};

// Class B, C are inherited from D
class D: public B, public C{

};
int main(){
	D object; // object creation of class D
	cout << "a = " << object.a << endl;
	return 0;
}