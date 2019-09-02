#include <iostream>
using namespace std;
#define SquareOf(x) x*x


int main()
{
  //int x = 10;
	//int &p = x; // aliases p to x => the address of p will be the same as x
	//cout<< &p<< &x; // print the address of x twice

    //const int m = 10;
    //int &n = m;
    //n = 11;

    //char X[3] = "abcd";
    //cout << X;
    /*
        int a = 10;
    int const &b = a;
    a = a +1 ;
    cout << b << a;
    cout << endl;

    const char cc = 'h';
    char *cp;
    const char *const ccpc = &cc;
    char *const *cpcp;

    cout << *ccpc;

    char a;
    const char aa = 'h';
    char *na;

    const char *naa;
    aa = a;
    na = &a;
    na = &naa;
  
    const char* c = "hello";

    //c = "H";

    cout << *c << " " << c;
    
    //int x;
    //cout << SquareOf(x + 4);
    int arr[] = {10,20,30};
    cout << -2[arr];

    class student{
        public:
            int no = 10;
        public: int get(){
            return no;
        }

    } v;
    cout << v.no;
    */
   int i= 13,  j = 60;
   i ^= j;
   cout << "i is: " << i;

	return 0;
}
