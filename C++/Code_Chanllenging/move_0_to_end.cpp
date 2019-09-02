#include <iostream>
#include <vector>
#include <string.h> 
#include <sstream>
using namespace std;

vector<int> move_zeros_to_end(vector<int>& vec){
    int num_zeros = 0;
    int size = vec.size();
    vector<int> new_vec;
    for(int i = 0; i < size; i++){
        if(vec[i] == 0){
            num_zeros += 1;
        } else{
            int not_zero = vec[i];
            new_vec.push_back(not_zero);
        }
    }
    for(int j = 0; j < num_zeros; j++){
        new_vec.push_back(0);
    }
    return new_vec;
}

int main(){
    int arr[6] = {1,0,2,3,0,5};
    vector<int> v(begin(arr),end(arr));
    vector<int> v2 = move_zeros_to_end(v);
    for(int i = 0; i < v2.size(); ++i){
        cout << v2[i] << endl;
    }
}