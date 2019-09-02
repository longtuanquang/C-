#include <iostream>
#include <thread>
#include <string>
#include <mutex>
#include <vector>
using namespace std;

class Wallet{
    int mMoney;
    std::mutex mutex;
public:
    Wallet():mMoney(0){}
    int getMoney(){return mMoney;}
    void addMoney(int money){
        std::lock_guard<std::mutex> lockGuard(mutex);
        for(int i = 0; i < money; ++i)
		    {
			// If some exception occurs at this
			// poin then destructor of lockGuard
			// will be called due to stack unwinding.
			mMoney++;
		    }
    }
    // Once function exits, then destructor
	// of lockGuard Object will be called.
	// In destructor it unlocks the mutex.
};
int testMultithreadedWallet()
{
    Wallet walletObject;
    std::vector<std::thread> threads;
    for(int i = 0; i < 5; ++i){
        threads.push_back(std::thread(&Wallet::addMoney, &walletObject, 1000));
        }
    for(int i = 0; i < threads.size() ; i++)
        {
        threads.at(i).join();
        }
    return walletObject.getMoney();
}
int main()
{
    int val = 0;
    for(int k = 0; k < 1000; k++)
    {
        if((val = testMultithreadedWallet()) != 5000)
        {
            std::cout << "Error at count = "<<k<<" Money in Wallet = "<<val << std::endl;
        }
    }
    return 0;
}