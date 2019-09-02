#include <iostream>
 #include <iomanip>
 #include <string>
 using namespace std;

 class Account{
     // String representing the name of the account's owner
     string name;
     int id;
     double balance;
     public:
        Account(const string& customer_name,int owner_id, double ammount ){
            name(customer_name), id(owner_id), balance(ammount);
            if(ammount < 0){
                std::cout << "Warning: negative account balance\n";
                balance = 0.0;
            }
        }

 }
 