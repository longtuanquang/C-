#include <string>
using namespace std;

int main(){
	// A normal integer varible
	int Var = 10;
	// A pointer that holds the address of Var
	int* p = &Var;

	//Print the value at address stored in *p
	printf("Value at address stored in *p is %d\n", *p);


	// Left side assignment value of Var
	*p = 20;
	printf("After assignment new value of Var %d\n: ", *p);

	// The address of Var 
	printf("The address of Var %p\n: ", p);
	printf("What is about &p %p\n", &p);

	unsigned int a = 0xff;
	printf("Line 1 - Original a %d\n", a);

	printf("Line 1 - Value of c is %d\n", a >> 4 );

	int b = 0xff;
	printf("Line 2 - Value of b is %d\n", b >> 4 );

}