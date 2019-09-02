#include <iostream>
#include <unordered_set>
#include <map>
#include <list>
#include <algorithm>
using namespace std;
//  Bo Quian Tutorial

int main(){
    /* UNORDERED_SET */
  unordered_set<int> s = {2, 4, 1, 8, 5, 9};
  unordered_set<int>::iterator itr;
  // Using member function
  itr = s.find(4); //O(1)
  // Using Algorithm
  itr = find(s.begin(), s.end(), 4); // O(n) 
  /* MAP */
  map<char, string> mymap = {{'S', "Sunday"}, {'M', "Monday"}, {'W', "Wednesday"}};
  // Using member function
  //itr = mymap.find('W'); // O(log(n)) - but only find a key
  // Using algorithm take O(n)
  //itr = find(mymap.begin(), mymap.end(), make_pair('F', "Friday")); // find a pair

    /* HOW ABOUT THE LIST */
    list<int> lst = {2, 4, 1, 8, 5, 9};
    // Using member function

    lst.sort();
    //for_each(lst.begin(), lst.end(), print_val);
    // Algorithm
    sort(lst.begin(), lst.end()); // Undefined behavior because the list is not random access.
    


}