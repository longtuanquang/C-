
#include <iostream>
#include <vector>
#include <string.h> 
#include <sstream>
#include <cstring>
using namespace std;

// Swap using c++
void swap_1 (string& str1, string& str2){
    string t = str1;
    str1 = str2;
    str2 = t;
}
// Swap using C => we have to swap 2 address of 2 pointers to strings
void swap_2(char** str1, char** str2){
    char* t = *str1;
    *str1 = *str2;
    *str2 = t;
}
int main(){
    string s1 = "geeks";
    string s2 = "for";
    swap_1(s1, s2);
    cout << "s1 is now :" << s1 << endl;

    char* str1 = "for geeks";
    char* str2 = " you can do it";
    swap_2(&str1, &str2);
    cout << "str1 is: " << str1 << endl;
    cout << "Int min is: " << INT_MIN << endl;
    cout << "Int max is: " << INT_MAX << endl;
    
}