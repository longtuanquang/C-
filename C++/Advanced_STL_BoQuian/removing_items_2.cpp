#include <iostream>
#include <vector>
#include <set>
#include <iterator>

using namespace std;
//Bo Quian Tutorial
/* MAIN IDEAS:
    1. Vector OR Deque: algorithm remove() followed by erase()
    2. List: member function remove
    3. Associate Container or Unordered container: erase()
*/
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
    //FOR ASSOCIATE CONTAINER print the message whenerver an item is removed
    multiset<int> c = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16};
    for(multiset<int>::iterator itr = c.begin(); itr!= c.end();){
        if(*itr == 1){
            cout << " Erased one item of " << *itr << endl;
            c.erase(itr++); // erase in associate returns nothing
        } else{
            itr++;
        }
    }
    print(c, "After erased: ");

    // FOR SEQUENCE CONTAINER
    vector<int> v = {1, 4, 6, 1, 1, 1, 1, 12, 18, 16};
    for(vector<int>::iterator itr = v.begin(); itr!=v.end();){
        if(*itr == 1){
            cout << " Erased one item of " << *itr << endl;
            itr = v.erase(itr); // after 1 is erase; itr points to the next element
            //cout << " Erased one item of " << *itr << endl;
        } else{
            itr++;
        }
    }

}