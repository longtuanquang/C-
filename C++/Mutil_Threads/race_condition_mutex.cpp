#include <iostream>
#include <thread>
#include <string>
#include <mutex>
using namespace std;

class LogFile{
    std::mutex m_mutex;
    ofstream f;
public:
    LogFile(){
        f.open("log.txt");
    } // Need destructor to close the file

    void shared_print(string msg, int val){
        std::lock_guard<mutex> locker(m_mutex);
        f << "From " << msg << ": " << val << endl;
    }

};

void function_1(LogFile& log){
    string s1;
    for(int i = 0; i > -100; i--){
        log.shared_print(string("From t1: "),i);
    }
}
int main(){
    LogFile log;
    std::thread t1(function_1, std::ref(log));
    for(int i = 0; i < 100; i++){
        log.shared_print(string("From main: "),i);
    }
    t1.join();
    return 0;
}