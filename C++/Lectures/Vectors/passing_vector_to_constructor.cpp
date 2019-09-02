#include <iostream>
#include <vector>
#include <cstdlib> // For rand

using namespace std;

class MyClass{
    private:
        vector<int>& vec;
    public:
        // Assign a vector to a constructor of a class
        MyClass(vector<int>& arr): vec(arr){

        }
        void print(){
            // print value of the vector
            for(int i = 0; i < vec.size(); i++){
                cout << vec[i] << " ";
            }
        }
};

int main(){
    vector<int> v;
    for(int i = 0; i < 5; i++){
        v.push_back(i);
    }
    MyClass myclass(v);
    myclass.print();
    return 0;
}