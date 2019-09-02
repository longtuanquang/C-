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
    // Add condition variable
    std::condition_variable m_conVar;
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
        // Notify the condition variable
        m_conVar.notify_one();
        
    }

    bool isDataLoaded(){
        return isLoaded;
    }

    void mainTask(){
        std::cout << "Do sthing with handshaking" << endl;
        // Acquire a lock
        std::unique_lock<std::mutex> mlock(m_mutex);
        //m_mutex.lock();
        // Start waiting for the Condition Variable to get signaled
        // Wait() will internally release the lock and make the thread to block
        // As soon as condition variable get signaled, resume the thread and
        // again acquire the lock. Then check if condition is met or not
        // If condition is met then continue else again go in wait.
        m_conVar.wait(mlock, std::bind(&Application::isDataLoaded,this));

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