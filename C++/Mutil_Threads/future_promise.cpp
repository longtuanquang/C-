#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <vector>
#include <future>
using namespace std;
//  Bo Quian Tutorial

int factorial(std::future<int>& f){
    int res = 1;
    int N = f.get();
    for(int i = 1; i <=N; i++){
        res *= i;
    }
    cout << "Result is: " << res << endl;
    return res;
}
int main(){
    int x;
    // a future object which you can get something in the future
    //std::future<int> fu = std::async(factorial,4); 
    // Use deffered for not creating a new thread
    //std::future<int> fu = std::async(std::launch::async | std::launch::deferred, factorial, 4);
    //x = fu.get(); // get() functions wait until the child finishes.
    //fu.get(); // crash program
    /* IN CASE, WE DONT HAVE THE VALUE N TO PASS IN THE PARAMETER OF 
    FACTORIAL FUNCTION => USE PROMISE OBJECT THAT GIVES THE VALUE LATER
    */
    std::promise<int> p;
    std::future<int> f = p.get_future();

    std::future<int> fu = std::async(std::launch::async, factorial, std::ref(f));

    // DO something else
    // Then, take a nap
    std::this_thread::sleep_for(chrono::milliseconds(20));
    // set value as our promise
    p.set_value(4);
    x = fu.get();
    cout << "Get from child: " << x << endl;
    //getchar();
    return 0;
}