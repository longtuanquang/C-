#include <iostream>
#include <vector>
#include <unordered_set>

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
  vector<int> v = {1, 3, 5, 4, 6, 1, 1 ,1, 7, 9}; // remove 1's 
  print(v, "Original");
/* BAD WAY TO MODIFY ALL ELEMENTS IN CONTAINER */
// Create an iterator
// for(vector<int>::iterator it = v.begin(); it != v.end();){
//     if(*it == 1){
//         it = v.erase(it);
//     } else{
//         it++;
//     }
// }// Complexity O(m*n)
// print(v, "After erase: ");

// GOOD WAY: USING ALGOTIHTM remove
auto itr = remove(v.begin(), v.end(), 1); // Complexity O(n) but it returns a pointer
v.erase(itr,v.end());
print(v, "After remove() :");
// Return unused memory back to the system
v.shrink_to_fit(); // C++11
// Check capacity of v
cout << "Capacity(): " << v.capacity() << endl;
}