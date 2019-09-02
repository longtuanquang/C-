#include <iostream>
using namespace std;
// Create a class Array with generic type T

template <typename T>
class Array {
private:
    T *ptr;
    int size;
public:
    Array(T arr[], int n);
    void print();
};

// Implement the constructor of Array
template <typename T>
Array<T>::Array(T arr[], int n){
    ptr = new T[n];
    size = n;
    for(int i = 0; i < n; i++){
        ptr[i] = arr[i];
    }
}
// Implement print function
template <typename T>
void Array<T>::print(){
    for(int i = 0; i < size; i++){
        cout << " " << *(ptr + i);
    }
    cout << endl;
}

int main() {
    //int arr[5] = {1, 2, 3, 4, 5};
    //Array<int> a(arr, 5); 
    //a.print(); 
    //return 0;
    int b, c;
    b = 10;
    c = b++;
    cout << " b is: " << b << ", c is: " << c;
    return 0;
}
