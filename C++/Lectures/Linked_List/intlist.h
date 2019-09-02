#include <iostream> 
using namespace std;


class Intlist
{
    // Member outside this class cannot access to the data
    /* data */
    struct Node {
        int data;
        Node *next;
        Node(int d); // Constructor
    };
    Node *head; // Point to the first element of the linked lis
    Node *tail;

    /*
     * The private following methods are helper methods that public
     * method invoke them to accomplish their tasks
     */
    // return the length of the linked list pointed by p
    int length(Node *p) const;
    // Deallocate the memory held by the list pointed by p
    void dispose(Node *p);
public:
    // Constructor make an initially empty list
    Intlist();
    // insert n onto the back of the linked list
    void insert(int n);
    // Print the contents of the linked list
    void print() const;

    // Returns the length of the linked list
    int length() const;

    // Remove all elements of the linked list
    void clear();
};
