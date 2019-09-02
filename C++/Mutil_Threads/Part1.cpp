#include <iostream>
#include <thread>
using namespace std;

void function_1(){
    std::cout << "Beautiful is on the skin-deep" << std::endl;
}
class Ffactor{
public:
    void operator()(){
        for(int i = 0; i < 100; i++){
            cout << "In t1: " << i << endl;
        }
    }
   
};

int main(){
    /* PART 1
    std::thread t1(function_1); // t1 starts running
    //t1.join(); // main thread waits for t1 to finish
    t1.detach(); // t1 will freely on its own -- daemon process, not connected to main
    if(t1.joinable()){
        t1.join();// crash if not check joinable
    }
    */
    /* PART 2
    */
    //Ffactor fct;
    //std::thread t1(Ffactor()); //it does not work, t1 is a function now, and returns a thread;
    std::thread t1((Ffactor())); // this works
    Ffactor fct;
    std:thread t1(fct);

    // Using RAII
    // Wrapper(t1);
    try{
        for(int i= 0; i < 100; i++){
                std::cout << "In main: " << i << endl;
            }
    } catch(...){
        t1.join(); // make sure that t1 will finish anyway.
        throw;
    }
    
    t1.join();
    
    return 0;
}