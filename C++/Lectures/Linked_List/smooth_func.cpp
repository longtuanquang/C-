#include <iostream> 
using namespace std;

class LinkedList{
    public: 
    static void foo(){
        cout << " This is public function! ";
    }
    public:
    struct Node{
        int data;
        Node* next;
        Node():data(0), next(nullptr){}
        Node(int val): data(val), next(nullptr){}
    };
        Node* head;
        Node* tail;
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
            while(cursur != nullptr){
                cout << cursur->data << ' ';
                cursur = cursur->next;
            }
            cout << endl;
        }
        Node* getHead(){
            return head;
        }

        void insert_newNode(Node* node){
             if(head == nullptr){// new Linked List
                head = tail = node;
            } else{
                tail->next = node;
                tail = node;
            }
        }
        Node* add_two_heads(LinkedList::Node* h1, LinkedList::Node* h2, int* carry);

        static int length(LinkedList::Node* node){
            if(node==nullptr){
                return 0;
            }
            return 1+ length(node->next);
        }
     
};
class A{};


LinkedList add_two_nums(LinkedList* L1, LinkedList* L2){
    // Initilizized a new LinkList
    LinkedList new_L;
    int carry = 0;
    while(L1->head != nullptr || L2->head !=nullptr){

        int temp = ((L1->head)? L1->head->data:0) +
                    ((L2->head)?L2->head->data:0);
        cout << "temp is: " << temp << endl;
        if(temp >= 10){
            temp = temp - 10 + carry;
            carry = 1;
        }
        else{
            temp = temp + carry;
        }
        //LinkedList::Node* new_Node = new LinkedList::Node(temp);
        new_L.insert(temp);
        if(L1->head != nullptr){
            L1->head = L1->head->next;
        }
         if(L2->head != nullptr){
            L2->head = L2->head->next;
        }
    }
    return new_L;
}


// Helper function to recursive call on head1, head2 and return new_head
LinkedList::Node* add_two_heads(LinkedList::Node* h1, LinkedList::Node* h2, int* carry){
    if(h1 == nullptr){
        return nullptr;
    } 
    //cout << "h1 data: " << h1->data << endl;
    LinkedList::Node* new_head = new LinkedList::Node;
    int sum;
    // Recursive add the remaining node and calculate carry
    new_head->next = add_two_heads(h1->next,h2->next, carry);
    sum = h1->data + h2->data + *carry;
    *carry = sum/10;
    sum = sum % 10;

    new_head->data = sum;
    cout << "NEW HEAD DATA: " << new_head->data << endl;
    return new_head;
    
}

int main(){
    LinkedList list1;
    int value1= 1;
    int value2 = 6;
    int value3 = 3;

    list1.insert(value1);
    list1.insert(value2);
    list1.insert(value3);
    list1.print();  

    LinkedList list2;
    int value4= 7;
    int value5 = 4;
    int value6 = 2;
    list2.insert(value4);
    list2.insert(value5);
    list2.insert(value6);
    list2.print();  

    //LinkedList L3;
    //L3 = add_two_nums(&list1, &list2);
    //L3.print();
    // Test length of linked list
    int len_ll = LinkedList::length(list1.getHead());
    cout << "Test length function: " << len_ll << endl;

    LinkedList L4;
    int i = 0;
    LinkedList::Node* node = add_two_heads(list1.getHead(), list2.getHead(), &i);
    
    //L4 = add_two_nums_recursive(&list1, &list2);
    L4.insert_newNode(node);
    L4.print();

    LinkedList::foo();
    return 0; 
}