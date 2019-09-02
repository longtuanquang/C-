#include <iostream>

struct Widget{
    int value;
    Widget(int val): value(val){
        std::cout << "Create widget " << value << '\n';
    } 
    ~Widget(){
        std::cout << "Destroying widget " << value << '\n';
    }
};

//Widget global_w(5);
Widget *get_widget(){
    // Caller must deallocate the returned object
    Widget *w = new Widget(10);
    return w;
}

void process(){
    Widget *p1 = get_widget();
    std::cout << p1->value << '\n';
    delete p1;
}
int main(){
    std::cout << "Entering main\n";
    process();
    std::cout << "Left main\n";
}
