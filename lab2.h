// 2. Implement  a  singly linked  list  class List and  write  a  member  function 
// void elementSwap(int pos ) to swap two adjacent elements pos and pos+1 of a singly linked list by adjusting only the 
// links (and not the data) 

#ifndef LAB2_H
#define LAB2_H

#include <iostream>
using namespace std;
struct Node
{

 int value;

 Node *next;

 Node( int value ) : value(value), next(0) {}
 

};

class List {
    private:
    Node *head;
    public:
    List();
    ~List();
    int size()const;
    void elementSwap(int pos);
    void print()const;
    void push_front(int value);
};

//Default constructor.
List::List() {
    head = 0;
}

List::~List() {
    while(head != 0) { // decontructs the list by moving head along until it reaches the end and deleting along the way
        Node * it = head;
        head = head->next;
        delete it;
    }
    delete head;
}
//Returns the number of nodes in the list.
int List::size() const {
    int sz = 0; //setting a return value intially 0
    Node *it = head;
    while( it != 0) { //while it is not at the end of the list increase the size byy one.
        sz = sz + 1;
        it = it->next;
    }
    return sz;
}
void List::elementSwap( int pos) { 
    if( pos + 1 >= size()) {
        cout << "Pos was to large" << endl;
        return;
    }
    Node *it = head; //iterator will point to pos
    Node *it2 = head; //iterator 2 will point to the position before position
    if( pos == 0) {
        Node *iter = head->next;
        Node *iterafter = iter->next;
        it->next = iterafter;
        iter->next = it;
        head = iter;
        return;
    }
    for( int i = 0; i < pos - 1; ++i) {
        it2 = it2->next;
    }
    for( int i = 0; i < pos; ++i) {
        it = it->next;
    }
    Node *iter = it->next;
    Node *iterafter = iter->next;
    it->next = iterafter;
    iter->next = it;
    it2->next = iter;
    
}
//Prints the contents of the list to cout
void List::print() const {
    if( head == 0) { //In case of empty set
        cout <<"Empty Set" << endl;
        return;
    }
    Node *it = head;
    for( unsigned i = 0; it != 0; ++i) { //prints out the values until the end of the list
        cout << it->value;
        it = it->next;
    }
    cout << endl;
}

//Inserts value at the front of the list.
void List::push_front(int value) {
    Node *it = new Node(value); //set it to a new node
    it->next = head; //setting it in fron of head
    head = it; //making head it
}
#endif /* LAB2_H */