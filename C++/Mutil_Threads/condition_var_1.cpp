#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <vector>
using namespace std;

// mainTask: thread 1 for handshaking and processing in data
// Thread 2: class application for loading data
class Application{
    std::mutex m_mutex;
    bool isLoaded;
public:
    Application(){
        isLoaded = false;
    }
    void loadData(){
        // 1. Sleeping in one second
        // 2. lock the mutex
        // 3. load data
        // 4. release the mutex
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        cout << "Loading data form XML" << endl;
        // Lock data structure
        std::lock_guard<std::mutex> guard(m_mutex);
        // Set flag to be true, meant data is loaded
        isLoaded = true;
    }
    void mainTask(){
        std::cout << "Do sthing with handshaking" << endl;
        // Acquire a lock
        m_mutex.lock();
        while(isLoaded != true){
            m_mutex.unlock();
            // Sleep in 100 miliseconds
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            m_mutex.lock();
        }
        m_mutex.unlock();
        //Doc processing data
        std::cout << "Processing in Data" << endl;
    }
};

int main(){
    Application app;
    std::thread thread_1(&Application::mainTask, &app);
    std::thread thread_2(&Application::loadData, &app);
    thread_1.join();
    thread_2.join();
    return 0;
}