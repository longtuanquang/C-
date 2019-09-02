/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

class LinkedList {
public:
    //static int carry;
    //carry = 0;
    struct ListNode{
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr){}
    };
    
    //get a len of the linke_list
    static int len_lst(ListNode* l1){
        if(l1 == nullptr){
            return 0;
        }
        else return 1 + len_lst(l1->next);
    }
    // Insert an int in front of a linked_list
    static void insert_front(ListNode** l1, int val){
        //cout << "INSERT STARTS: !!!" << endl;
        //ListNode* temp = l1;
        ListNode* new_node = new ListNode(val);
        //cout << "new node val: " << new_node->val << endl;
        new_node->next = *l1;
        *l1 = new_node;
        //cout << "New l1 is : " << *l1->next->val << endl;
        //l1->next = new_node->next;
        //return l1;
    }
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Insert Zero to the shorter link list
        int l1_len = LinkedList::len_lst(l1);
        int l2_len = LinkedList::len_lst(l2);
        if(l1_len < l2_len){
            //number of zeroes inserted in front of the l1
            int num_zeores = l2_len - l1_len;
            for (int i = 0; i < num_zeores; ++i){
                LinkedList::insert_front(&l1, 0);
            }
        }
        if (l2_len < l1_len){
             //number of zeroes inserted in front of the l2
            int num_zeores = l1_len - l2_len;
            for (int i = 0; i < num_zeores; ++i){
                LinkedList::insert_front(&l2, 0);
            }
        }
        // NOW two linked lists have the same length
        //TODO: Add two numbers from the end of linked lists first
            // base case
            //ListNode new_node = new ListNode(0);
            //new_node->next = add_helper(&l1, &l2, 0);
            int carry = 0;
            return LinkedList::add_helper(l1, l2,&carry);
        
    }
    static ListNode* add_helper(ListNode* l1, ListNode* l2, int* carry){
        if(l1 == nullptr){
            return nullptr;
        }
        ListNode* new_node = new ListNode(0);
        new_node->next = add_helper(l1->next,l2->next, carry);
      
        int sum = (l1->val + l2->val + *carry)%10;
        *carry = (l1->val + l2->val + *carry) >= 10 ? 1 : 0;
        
        
        // Case [5] & [5] => len of l1 == 1
        if(len_lst(l1)==1){
            cout << "Carry is: " << *carry << endl;
            if(*carry ==1){
                // New node become head with val =1
                new_node->val = 1;
                // temp is the next node with some
                ListNode* temp = new  ListNode(sum);
                new_node->next = temp;
            } else {
                new_node->val = sum;
            }
            
        } else{
            new_node->val = sum;
        }
        return new_node;
        
    }
      static void print(ListNode* node){
        while(node != nullptr){
            cout << "Node is: " << node->val << " ";
            node = node->next;
        }        
        cout << endl;
    }
    
    // Insert to the back of ListNode
    static void insert(ListNode* node, int val){
        ListNode* temp = node;
        while(temp->next != nullptr){
            temp= temp->next;
        }
        ListNode* new_node = new ListNode(val);
        //node = node->next;
        temp->next = new_node;
        
    }
};
int main(){
    
    LinkedList::ListNode* l1 = new LinkedList::ListNode(7);
    LinkedList::insert(l1, 2);
    LinkedList::insert(l1, 4);
    LinkedList::insert(l1, 3);
    //LinkedList::print(l1);

    LinkedList::ListNode* l2 = new LinkedList::ListNode(5);
    LinkedList::insert(l2, 6);
    LinkedList::insert(l2, 4);
    //LinkedList::insert(l2, 4);
    LinkedList::print(l2);

    // Test function len of linked list
    int len_l1 = LinkedList::len_lst(l1);
    cout << "Length of linked list 1 is: " << len_l1 << endl;
    //Test insert front of linked list
    LinkedList::insert_front(&l1, 100);

    cout << "PRINT LINKED LIST 1 AGAIN" << endl;
    //LinkedList::print(l1);

    LinkedList::ListNode* l3 = LinkedList::addTwoNumbers(l1,l2);
    LinkedList::print(l3);
    
    /*
    LinkedList::ListNode* l5 = new LinkedList::ListNode(5);
    LinkedList::ListNode* l6 = new LinkedList::ListNode(5);

    LinkedList::ListNode* l7 = LinkedList::addTwoNumbers(l5,l6);
    LinkedList::print(l7);
     */
    
    
}