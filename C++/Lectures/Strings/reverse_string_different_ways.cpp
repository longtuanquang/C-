#include <iostream>
#include <vector>
#include <string.h> 
#include <sstream>
#include <cstring>

using namespace std;
void swap_manual(char* a, char* b);

// THIS IS METHOD FOR C
char* reverse_string_1(char const* str){
    int start;
    int n = strlen(str);
    // create a dynamic pointer char array
    char *new_str = new char[n+1];
    int end = n - 1;
    for(start = 0; start < n; start++){
        //cout << str[end];
        new_str[start] = str[end];
        end--;
        //cout << new_str[start];
    }
    //cout << new_string;
    new_str[start+1] = '\0';
    return new_str;
}
// WE CAN SWAP A STRING BY ITSELF
void reverse_string_2(string& str){
    int n = str.size();
    for(int i = 0; i < n/2; i++){
        char temp;
        temp = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = temp;
    }
}
void swap_manual(char* a,char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

/*
int main(void){
    const char* str = "abc";

    printf("%s",reverse_string_1(str));
    cout << endl;
    //cout << new_string;
    //cout << new_string.size();
    printf("%s",str);

    string str_2 = "abchdef";
    reverse_string_2(str_2);
    cout << endl;
    cout << str_2;
    char a = 'a';
    char b = 'b';
    swap_manual(&a,&b);
    cout << "a is :" << a << "b is : " << b;
    return (0);
}
*/