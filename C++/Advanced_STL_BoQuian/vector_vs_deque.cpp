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

int main(){
    vector<int> v = {1, 4, 6, 1, 1, 1 ,1 , 12,18};
  

}