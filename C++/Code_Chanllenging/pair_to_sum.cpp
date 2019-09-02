#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
int pair_to_sum(const vector<int> data, int target){
    unordered_set<int> comp; // complement
    for(int value: data){
        if(comp.find(value) != comp.end()){
            return true;
        }
        comp.insert(target - value);
    } 
    return false;
    
}

int main(){
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(9);

    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(4);
    v2.push_back(4);


    cout << "Check pair to Sum v1: " << pair_to_sum(v1, 8) << endl;
    cout << "Check pair to Sum v2 " << pair_to_sum(v2, 8) << endl;
}