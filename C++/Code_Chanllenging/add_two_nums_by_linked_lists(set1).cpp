#include <iostream> 
using namespace std;

class LinkedList{
    struct Node{
        int data;
        Node* next;
        Node(int val): data(val), next(nullptr){}
    };
    Node* head;
    Node* tail;
    public:
        // constructor of LinkedList
        LinkedList(){
            head = nullptr;
            tail = nullptr;
        }
        // insert to the back of linkedlist
        void insert(int val){
            LinkedList::Node* newNode = new Node(val);

            if(head == nullptr){// new Linked List
                head = tail = newNode;
            } else{
                tail->next = newNode;
                tail = newNode;
            }
        }
        void print(){
            Node* cursur = head;
            while(cursur->next != nullptr){
                cout << cursur->data << ' ';
                cursur = cursur->next;
            }
            cout << endl;
        }
};

int main(){
    LinkedList list;
    int value1= 5;
    int value2 = 6;
    int value3 = 3;

    list.insert(value1);
    list.insert(value2);
    list.insert(value3);
    list.print();  
    return 0; 
}