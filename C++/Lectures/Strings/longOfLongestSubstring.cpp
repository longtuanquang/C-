#include <iostream>
#include <vector>
#include <string.h> 
#include <sstream>
using namespace std;
int find_max(const vector<int>& v);

int longest_substring(string str) {
        if(str == ""){
            return 0;
        }
        vector<int> idx_vec;
        string sub_str("");
        sub_str += str[0];
        idx_vec.push_back(1);
        // len of string
        int n = str.length();
        // Iterate all string
        cout << "Star a loop!!";
        for(int i = 1; i < n; i++){
            int found_idx = sub_str.find(str[i], 0);
            // found a char at i in substring
            if(found_idx != -1){
                // reset idx_vec[i] and sub_str
                sub_str = sub_str.substr(found_idx + 1,sub_str.length() - 1) + str[i];
                idx_vec.push_back(sub_str.length());
                //cout << "Found !!!"  << endl;

            } else{
                int temp = idx_vec[i-1] + 1;
                idx_vec.push_back(temp);
                sub_str += str[i];
                //cout << "Not found!!!" << endl;
            }
        }
        for(int i = 0; i < idx_vec.size();++i){
            cout << idx_vec[i] << " ";
        }
        return find_max(idx_vec);
        }
// find_max in a vector
int find_max(const vector<int>& v){
    int max = 0;
    for (int i = 0; i < v.size(); ++i){
        if(v[i] > max){
            max = v[i];
        }
    }
    return max;
}

/*
int main(){
    string s = "pwwkew";
    int n = longest_substring(s);
    cout << "The longest substring is: " << n << endl;

    string s2 = "devdf";
    int n2 = longest_substring(s2);
    cout << "The longest substring s2 is: " << n2 << endl;
    int u = s.find("h",0);
    cout << "What is if not found h: " << u << endl;

    return 0;
}
*/