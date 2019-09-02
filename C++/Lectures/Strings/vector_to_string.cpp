#include <iostream>
#include <vector>
#include <string.h> 
#include <sstream>
using namespace std;

// Write a function convert vector to string
string vector_to_string(vector<string>& vec, char saparator);
string trim_white_space(string);
int main(){
    vector<string> vec(3);
    vec[0] = "Bob";
    vec[1] = "Sue";
    vec[2] = "Dan";
    string theString = vector_to_string(vec, ' ');
    cout << theString;

    
    return 0;
}

string vector_to_string(vector<string>& vec, char saparator){
    string theString = "";
    // Iterate each word in vector
    for(auto word: vec){
        theString += word + saparator;
    }
    return theString;
}

string trim_white_space(string theString){
    string white_space(" \t\f\n\n");
    theString.erase(theString.find_last_not_of(white_space) +1);
    theString.erase(0, theString.find_first_not_of(white_space));
    return theString;
}