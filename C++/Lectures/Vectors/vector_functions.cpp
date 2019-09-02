#include <iostream>
#include <vector>
#include <cstdlib> // For rand

using namespace std;

// PASS BY VALUE: copy  a vector to parameter v => NOT EFFECIENT
void print(vector<int> v){
    for(int elem: v){
        cout << elem << " ";
        cout << '\n';
    }
}
// PASS BY REFERENCE OF A VECTOR
void print_by_reference(vector<int>& v){
     for(int elem: v){
        cout << elem << " ";
        cout << '\n';
    }
}

/*
  *  make_random(v)
  *     Fills an int vector with pseudorandom numbers
  *     v is the vector to fill; v is modified
  *     size is the maximum size of the vector
  */
void make_random(vector<int>& v, int size){
    v.clear(); // empty content of vector v
    int n = rand() % size + 1;
    for(int i= 0; i< n; i++){
        v.push_back(rand()); // Populate with random values
    }
}


int main(){
    int arr[4] = {10, 20, 30, 40};
    // Convert array to vector: way1
    int n = sizeof(arr)/sizeof(arr[0]);
   vector<int> v(arr, arr+n);
    // Convert array to vector: 2nd way
    vector<int> v2(begin(arr),end(arr));

   //print(v);
   //print(v2);
   print_by_reference(v2);
}
