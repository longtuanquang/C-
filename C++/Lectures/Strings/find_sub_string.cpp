#include <iostream>
#include <vector>
#include <string.h> 
#include <sstream>
using namespace std;

vector<int> find_index_match(string&, string&);
int main(){
    string str1 = "to be or not to be";
    string sub_str = "be";
    vector<int> ind_vec = find_index_match(str1, sub_str);
    for(int i = 0; i < ind_vec.size(); i++){
        cout << ind_vec[i] << " ";
    }
    cout << endl;
}

vector<int> find_index_match(string& str1, string& sub){
    // Declare vector to store index match in string
    vector<int> vec;
    // find the first index of matching
    int index = str1.find(sub,0);
    while(index != str1.npos){
        vec.push_back(index);
        index = str1.find(sub,index +1 );
    } 
    return vec;
}