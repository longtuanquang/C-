#include <iostream>
#include <vector>
#include <string.h> 
#include <sstream>
#include <cstring>

using namespace std;

char* reverse_string(char const* str){
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
int main(void){
    const char* str = "abc";
    printf("%s",reverse_string(str));
    return (0);
    //cout << new_string;
    //cout << new_string.size();
}