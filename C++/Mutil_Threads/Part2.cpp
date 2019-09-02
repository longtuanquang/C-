#include <iostream>
#include <thread>
#include <string>
using namespace std;

class Ffact{
public:
    void operator()(){
        cout << "Child thread says: " << endl;
        // Try to change s
        //msg = "Trust is mother of love!";
    }
};

int main(){
    cout << "This is main thread";
    cout << std::this_thread::get_id() << endl;
    
    //std::thread t1((Ffact()),std::ref(s));
    //std::thread t1( (Ffact()), std::move(s) ); // move s from main to t1 and copy by reference
    std::thread t1( (Ffact()) );
    cout << "t1 id is: " << t1.get_id();
    t1.join(); // make sure t1 will be finish

    cout << "In main: " << endl;
    
    return 0;
}