#include <iostream>
using namespace std;

enum colour = {Red, Green, Yellow};
struct apple{
    float weight;
    colour c;
};

int main(){
    apple myApple;
    myApple.weight = 75.6;
    myApple.colour = Red;
}