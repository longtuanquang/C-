#include <iostream>
#include <thread>
#include <string>
#include <vector>
#include <mutex>
#include <algorithm>
using namespace std;

// Create a 10 WorkerThread 
class WorkerThread{
public:
    void operator()(){
        std::cout << "Worker Thread: " << std::this_thread::get_id() << "is_executing" << endl; 
    }
};

int main(){
    std::vector<std::thread> thread_list;
    // create a list of 10 workers
    for(int i = 0; i < 10; i++){
        thread_list.push_back(std::thread( WorkerThread() ));
    }
    //Now wait for all the worker thread to finish i.e.
    // Call join() function on each of the std::thread object
    std::cout<<"wait for all the worker thread to finish"<<std::endl;
    std::for_each(thread_list.begin(), thread_list.end(), std::mem_fun(&std::thread::join));
    std::cout<<"Exiting from Main Thread"<<std::endl;
    return 0;

}