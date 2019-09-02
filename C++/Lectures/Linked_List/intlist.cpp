#include "intlist.h"
#include <iostream> 
using namespace std;

// Private Intlist operation
Intlist::Node::Node(int d): data(d), next(nullptr){}

int Intlist::length(Intlist::Node *p) const {
    // using recursive to find length of Intlist
    if(p)
        return 1 + length(p->next);
    else
    {
        return 0;
    }  
} 

void Intlist::dispose(Intlist::Node *p){
    if(p){
        dispose(p->next); // Free up the rest of the list
        delete p;   // Deallocate this node
    }
}
//Public Intlist operation
Intlist::Intlist(): head(nullptr), tail(nullptr){}

// Implement insert(n): insert to the back of Intlist
void Intlist::insert(int n){
    // create a new node
    Intlist::Node *new_node = new Node(n);
    if(tail){
        tail->next = new_node;
        tail = new_node;
    } else{
        // If List is empty
        head = tail = new_node;
    }
}

// print the contents of the linked list
void Intlist::print() const {
    for(auto cursor = head; cursor; cursor = cursor->next){
        cout << cursor->data << ' ';
    }
    cout << '\n';
}
// Return the length of the linked list
int Intlist::length() const {
    return length(head);
}

// Clear Remove all the elements int the linked list
void Intlist::clear(){
    dispose(head); // Deallocate space for all nodes
    head = tail = nullptr;
}


int main(){
    Intlist list;
    int value1= 5;
    int value2 = 6;
    int value3 = 3;

    list.insert(value1);
    list.insert(value2);
    list.insert(value3);
    list.print();  
    return 0; 
}