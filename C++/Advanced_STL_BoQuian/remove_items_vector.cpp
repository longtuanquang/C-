#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;
// print the content of the container
template<class T>
void print(T t, string msg){
    cout << msg << " { ";
    for(typename T::iterator it = t.begin(); it != t.end(); it++){
        cout << *it << ", ";
    }
    cout << "}" << endl;
}

// Function to check equal one, then remove it
bool equalOne(int x, int p){
    if(x == p){
        cout << x << " will be removed!" << endl;
        return true;
    }
    else
    {
        return false;
    }
    
}
int main(){
    // Print the messgage whenerver a item is removed
    vector<int> v = {1, 4, 6, 1, 1, 1 ,1 , 12,18};
    auto itr = remove_if(v.begin(), v.end(), bind(equalOne,placeholders::_1,1));
    v.erase(itr, v.end());
    print(v, "After removed");

}