#include <iostream>
#include <vector>
#include <string.h> 
#include <sstream>
using namespace std;

// Write a function convert a string to vector

vector<string> string_to_vector(const string& str, char separator){
    // Declare a new vector type string
    vector<string> vec;
    // Break a string into tokens using stringstream
    stringstream ss(str);
    string word; // to store individual words
    while(getline(ss, word, separator)){
        vec.push_back(word);
    }
    return vec;
}

int main(){
    string s = "This is a random string";
    vector<string> vec = string_to_vector(s, ' ');
    for(int i = 0; i < vec.size(); ++i){
        cout << vec[i] << "\n";
    }
    return 0;
}