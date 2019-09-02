#include <iostream>
#include <iostream>
using namespace std;

int main(){
    // Prompt user for input
    int num1,num2;
    cout << "Please enter two integers: ";
    cin >> num1 >> num2;
    // Determin the smallest number b/w two numbers
    int min = (num1 < num2) ? num1 : num2;
    // 1 is denefintely a common factor of these two numbers
    int lagest_factor = 1;
    for(int i = 2; i < min; i++){
        if(num1 % i == 0 && num2 % i == 0){
            lagest_factor = i;
        }
    }
    cout << "Common largest factor: " << lagest_factor << '\n';

}