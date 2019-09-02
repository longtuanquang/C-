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
    struct ListNode{
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(nullptr){}
    };
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = (l1->val + l2->val)%10;
        int carry = (l1->val + l2->val) >= 10 ? 1 : 0;
        ListNode* new_lst = new ListNode(sum);
        //cout << "The first element is: " << new_lst->val;
        l1 = l1->next;
        l2  = l2->next;
        ListNode* tail = new_lst;
        while(l1 != nullptr){
            int l1_val = (l1 !=nullptr) ? l1->val : 0;
            int l2_val = (l2 !=nullptr) ? l2->val : 0;
            sum = (l1_val + l2_val + carry)%10;
            carry = (l1_val + l2_val + carry) >= 10 ? 1 : 0;
            //cout << " Sum is : " << sum << endl;
            tail->next = new ListNode(sum);
            //cout << "The next element is: " << tail->val;
            l1 = (l1 != nullptr) ? l1->next : nullptr;
            l2 = (l2 != nullptr) ? l2->next : nullptr;
            tail = tail->next;
        }
        if(carry == 1){
            tail->next = new ListNode(1);
        }
        return new_lst;
        
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
    static void print(ListNode* node){
        while(node != nullptr){
            cout << "Node is: " << node->val << " ";
            node = node->next;
        }        
        cout << endl;
    }
};
int main(){
    LinkedList::ListNode* l1 = new LinkedList::ListNode(2);
    LinkedList::insert(l1, 4);
    LinkedList::insert(l1, 3);
    LinkedList::print(l1);

    LinkedList::ListNode* l2 = new LinkedList::ListNode(5);
    LinkedList::insert(l2, 6);
    LinkedList::insert(l2, 4);
    LinkedList::print(l2);

    LinkedList::ListNode* l3 = LinkedList::addTwoNumbers(l1,l2);
    LinkedList::print(l3);

}