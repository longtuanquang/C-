#include <iostream>
#include <vector>
#include <string.h> 
using namespace std;


bool isDigit(char c){
    const char zero = '0';
    return (c - zero < 10 && c - zero > 0);
}
int Atoi(string s){
    int n = s.length();
    const char zero = '0';
    int pos = 1;
    int neg = -1;
    int sign = 0;
    char space = ' ';
    bool flag = false;
    int myNum = 0;
    // Check for overflow
    const int pos_head = INT_MAX/10;
    const int pos_tail = INT_MAX%10;
    const int neg_head = INT_MIN/10;
    const int neg_tail = pos_tail + 1;

    for(int i = 0; i < n ; i++){
        char c = s[i];
        //cout << "char c is: " << c << endl;
        if(c == space && flag == false){
            continue;
        }
        else if(c == '+'){
            sign = pos;
            continue;
        }
        else if(c == '-'){
            sign = neg;
            //cout << "sign is: " << sign << endl;
            continue;
        }
        

        else if(isDigit(c)){
            if(!flag){
                myNum = c - zero;
                //cout << "My num is: " << myNum << endl;
                flag = true;
            }
            else
            {
                myNum = myNum*10 + c - zero;
                //cout << "My num is: " << myNum << endl;
            }
        }
        else if(flag == true && !isDigit(c)){
            break;
        }
    }
    //cout << "Flag is: " << flag << endl;
    if(flag == 0){
        return 0;
    } else{
        //cout << "sign is: " << sign << endl;
        return sign*myNum;
    }
    
    
}

int main(){
    char c1 = 'a';
    char c2 = '2';
    cout << isDigit(c1) << endl;
    cout << isDigit(c2) << endl;
    string str = "      -42   sllls";
    int output = Atoi(str);
    cout << output << endl;

}