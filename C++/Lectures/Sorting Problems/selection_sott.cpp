#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

void selection_sort(vector<int>& v1){
    // len of a vector
    int len = v1.size();
    for (int i = 0; i < len - 1; ++i){
        int small_idx = i;
        for (int j = i + 1; j < len; ++j){
            if(v1[j] < v1[small_idx])
                small_idx = j;
        }
        if(i != small_idx){
            swap(v1[i], v1[small_idx]);
        }
    }
}

int main(){
    int arr[] = {64, 25, 12, 22, 11};
    vector<int> v2(begin(arr),end(arr));
    selection_sort(v2);
    for(int i = 0; i < v2.size(); ++i){
        cout << v2[i] << " ";
    }
}