#include <string>
#include <iostream>
using namespace std;

int main(){
	// A normal integer varible
	int Var = 10;
	// A pointer that holds the address of Var
	int* ptr = &Var;

	//Print the value at address stored in *p
	printf("Value at address stored in *p is %d\n", *ptr);


	// Left side assignment value of Var
	*ptr = 20;
	printf("After assignment new value of Var %d\n: ", *ptr);

	// The address of Var 
	printf("The address of Var %p\n: ", ptr);
	printf("What is about &p %p\n", &ptr);

	int arr[5] = {1,6,9,10,11};
	int *p = arr;
	*p++;
	//cout << "++*p is: " << ++*p << endl;
	 cout << "*p++ is: " << *p << endl;
	//cout << "*++p is: " << *++p << endl;

	cout << "2 6 6";

}