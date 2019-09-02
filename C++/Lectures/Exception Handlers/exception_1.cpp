#include <iostream>
#include <exception>
#include <iomanip>

using namespace std;
class A;

class myException: public exception{
    virtual const char* what() const throw(){
        return "My exception happended! ";
    }
}myex;

int main(){
    /* 
        try {
        throw 20;
    }
    catch(int e){
        cout << " An exception occurs " << e << endl;
    }
    catch (...) {
        cout << "default exception !" << endl; // catch any exception no matter what type of exception
    }
   
   try {
       int* my_arr= new int[1000];

   }
   catch (exception& e){
       cout << "Standard Exception: " << e.what() << endl;
   }
    */
   //float x = 3.1419;
   //cout << setprecision(2) << x;
   /*
    char a[] = { 'A', 'B', 'C', 'D' }; 
   char* ppp = &a[0];
   cout << "FIRST *ppp is now: " << *ppp << endl;
   *ppp++; // Line 1 
   cout << "*ppp is now: " << *ppp << endl;
   printf("%c %c ", *++ppp, --*ppp); // Line 2 
   
    char a[] = { 'A', 'B', 'C', 'D' }; 
   char* ppp = &a[0];
   cout << "FIRST *ppp is now: " << *ppp << endl;
   *ppp++; // Line 1 
   cout << "*ppp is now: " << *ppp << endl;
   printf("%c %c ", *++ppp, --*ppp); // Line 2 
    
    int n = 21; 
    std::cout << std::dec << "dec - " << n << '\n'; 
    std::cout << std::hex << "hex - " << n << '\n'; 
    std::cout << std::oct << "oct - " << n << '\n'; 
    //std::cout << std::base(2) << "base 2 " << n << '\n'; 
    //A a;

    for(int i = 0; i < 3 ; ++i){
        switch (i)
        {
        case 0:
            cout << "zero";
        case 1:
            cout << "one";continue;
        
        case 2:
            cout << "two";break;
        default:
            cout <<"Endl" << endl;
        }
    }
    */

    
    return 0; 
 

   

   //cout << "*++ppp is :" << *++ppp << endl;
   //cout << "--*ppp is :" << --*ppp << endl;
   
   //return 0;
}