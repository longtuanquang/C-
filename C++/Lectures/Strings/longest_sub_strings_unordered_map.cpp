#include <iostream>
#include <vector>
#include <string.h> 
#include <sstream>
#include "cmath"
#include <unordered_map>
using namespace std;

int longest_substring(string str) {
    int global_max = 0;
    int sub_max = 0;
    // Create a dictionary
    unordered_map<char,int> map;
    int n = str.length();
    // Initialize unordermap
    for(int i = 0; i < n ; i++){
        //map.at(str[i]) = -1;

        map[str[i]] = -1;
    }
    for(int i = 0; i < n; i++){
        // if str[i] not in substring
        if(map.at(str[i]) == -1){
            map.at(str[i]) = sub_max;
            ++sub_max;
            if(sub_max > global_max)
                global_max = sub_max;
        }
        else{
            // if str[i] in substring
            // get the location of str[i] in substring
            int slide = map.at(str[i]) + 1;
            cout << "Index of char " << str[i] << " is: " << slide << endl;
            for(pair<char, int> elem: map){
                if(elem.first == str[i]){
                    elem.second = sub_max - slide;
                } else{
                     if(elem.second != -1){
                    // this element in a substring
                    elem.second = elem.second - slide;
                    sub_max = sub_max - slide + 1;
                    }
                }
               
                    
            }
        }
    }
    return global_max;

}
int main(){
    string s1 = "abcdb";
    int n1 = longest_substring(s1);
    cout << "Longest substring is: " << n1 << endl;
}