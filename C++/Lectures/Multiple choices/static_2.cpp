#include<iostream>
using namespace std;
 
int &fun()
{
    const int x = 10;
    return x;
}
int main()
{
    fun() = 30;
    cout << fun();
    return 0;
}