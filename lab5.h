// -*- bst.h -*-
#ifndef BST_H
#define BST_H
#include <cassert>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <sstream>
#include <map>
#include <list>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
#define nil 0

// #define Value int // restore for testing.
template < typename Value >
class BST {
    class Node { // binary tree node
        public:
        Node* left;
        Node* right;
        Value value;
        Node( const Value v = Value() )
        : value(v), left(nil), right(nil)
        {}
        Value& content() { return value; }
        bool isInternal() { return left != nil && right != nil; }
        bool isExternal() { return left != nil || right != nil; }
        bool isLeaf() { return left == nil && right == nil; }
        int height() {
            Node* it = root; // sets a node to the root
            while( it->value != content()) { //until the it is equal to the value of the begining of the sub tree
                if( it ->value < content()) { //if the value is smaller move it right
                    it->right;
                }
                if(it->value > content()) { //if the value is greater move it left
                    it->left;
                }
            }
            int hei = 0;
            return heighthelp(it);
        // returns the height of the subtree rooted at this node
        // FILL IN DONE
        }
        int heighthelp(Node *it) {
            if( it == NULL) {
                return 0;
            }
            if(heighthelp(it->left) > heighthelp(it->right)) {
                return heighthelp(it->left) + 1;
            }
            if(heighthelp(it->left) < heighthelp(it->right)) {
                return heighthelp(it->right) + 1;
            }
        }
        int size() { // not given a parameter so I think I'll have to find it
            Node* it = root; // sets a node to the root
            while( it->value != content()) { //until the it is equal to the value of the begining of the sub tree
                if( it ->value < content()) { //if the value is smaller move it right
                    it->right;
                }
                if(it->value > content()) { //if the value is greater move it left
                    it->left;
                }
            }
            
            return sizehelp(it);
        // returns the size of the subtree rooted at this node,
        // FILL IN DONE
            
        }
        void sizehelp(Node *it) {
            if(root->left == NULL) {
                return 0;    
            }
            
            else {
                
                return 1 + sizehelp(it->left) + sizehelp(it->right); // adding one for the parent of the nodes to the next left and right nodes
            }
        }
    }; // Node

// const Node* nil; // later nil will point to a sentinel node.
    Node* root;
    int count;
    int min = 0;
    vector <int> x;
    vector <int> y;
    public:
    int size() {
        Node *it = root;
        
        return sizehelp(it); //same thing as the previous size thing pretty much
        
        // size of the overall tree.d
        // FILL IN DONE
    }
    void minCover() {
        Node *it = root;
        minCoverhelp(it);
    }
    
    void minCoverhelp( Node *n) {
        if(root->left == NULL && n->left == NULL) {
            minCoverhelp( n->right);
        }
        if( n->left != NULL) { // keeps going until n points to the node before null
            minCoverhelp( n->left); //checks out the left side
            if(n->left != NULL || n->right != NULL) {
                min = min + 1;
                x.push_back(n->value);
            }
            minCoverhelp( n->right); //checks out the right side
        }
        
    }

    void displayMinCover() {
        for( int i = 0; i < x.size(); ++i) {
            cout << x.at(i);
        }
        cout << endl;
        cout << min << endl;
    }
    
    void  findSumPath(Node*  n, int sum,  int  buffer[]) {
        
        sum = sum - n->value;
        if( sum < 0) {
            y.pop_back();
            return;
        }
        if( sum == 0) {
            displaySumPath();
        }
        if(root->left == NULL && n->left == NULL) {
            y.push_back(n->value);
            findSumPath(n->right, sum, buffer);
        }
        if( sum < n->value) {
            y.push_back(n->value);
            n = n->left;
            findSumPath(n, sum, buffer);
        }
        else {
            
            y.push_back(n->value);
            findSumPath(n->value, sum, buffer);
            y.push_back(n->value);
            n = n->right;
            findSumPath(n->value, sum, buffer);
        }
        
    }
    void displaySumPath() {
        for( int i = y.size() - 1; i > -1; --i) {
            cout << y.at(i);
        }
    }
    //     bool search ( Value x ) {
    //     // search for a Value in the BST and return true iff it was found
    //     Node *it = root;
    //     while(it->value != NULL) {  //searching until it hits a NULL
    //         if( it->value > x) { // if it is less than x move it left
    //             it = it->left;
    //         }
    //         if (it->value < x){//if it is greater than x move it right
    //             it = it->right;
    //         }
    //         if( it->value == x) { //congratz the value was found
    //             return true;
    //         }
    //     }
    //     return false;
    //     // FILL IN DONE
    // }
    
    void vertSum(Node*  node,  int  hd,  std::map<int,  int>&m) {
        if(root->left == NULL && node->left == NULL) {
            
            m[hd] = m[hd] + node->value;
            hd = hd + 1;
            vertSum(node->right, hd, m);
        }
        if( node->left != NULL) { // keeps going until n points to the node before null
            m[hd] = m[hd] + node->value;
            hd = hd - 1;
            vertSum(node->left, hd, m);
            
            m[hd] = m[hd] + node->value;
            hd = hd + 1;
            vertSum(node->right, hd, m);
            
        }
    }
    
    
    int sizehelp(Node *it) {
        if( it == NULL) { //base case when it reaches null
            return 0;
        }
        else {
            
            return 1 + sizehelp(it->left) + sizehelp(it->right); // adding one for the parent of the nodes to the next left and right nodes
        }
    }
    
    bool empty() { return size() == 0; }
    void print_node( const Node* n ) {
        // Print the node’s value.
        // FILL IN DONE
        cout << n->value << " " << endl;
    }
    
    bool search ( Value x ) {
        // search for a Value in the BST and return true iff it was found
        Node *it = root;
        while(it->value != NULL) {  //searching until it hits a NULL
            if( it->value > x) { // if it is less than x move it left
                it = it->left;
            }
            if (it->value < x){//if it is greater than x move it right
                it = it->right;
            }
            if( it->value == x) { //congratz the value was found
                return true;
            }
        }
        return false;
        // FILL IN DONE
    }
    void preorder()const {
        Node *it = root;
        preorderhelp(it);
        // Traverse and print the tree one Value per line in preorder.
        // FILL IN
    }
    void preorderhelp(Node *n) const{
        
        if(root->left == NULL) {
            print_node(n);
            n = n->right;
            
        }
        if( n->left != NULL) { // keeps going until n points to the node before null
            print_node(n); //prints out the node
            inorderhelp( n->left); //checks out the left side
            inorderhelp( n->right); //checks out the right side
        }
    }
    void postorder()const {
        Node *it = root;
        postorderhelp(it);
        // Traverse and print the tree one Value per line in postorder
        // FILL IN
    }
    void postorderhelp(Node *n)const {
        if(root->left == NULL) {
            n = n->right;
            print_node(n);
        }
        if( n->left != NULL) { // keeps going until n points to the node before null
            inorderhelp( n->left); //checks out the left side
            inorderhelp( n->right); //checks out the right side
            print_node(n); //prints out the node
        }
    }
    void inorder()const {
        Node *it = root;
        inorderhelp(it);
        
        // Traverse and print the tree one Value per line in inorder.
        // FILL IN
    }
    void inorderhelp(Node *n) const{
        if(root->left == NULL) {
            print_node(n);
            n = n->right;
        }
        if( n->left != NULL) { // keeps going until n points to the node before null
            inorderhelp( n->left); //checks out the left side
            print_node(n); //prints out the node
            inorderhelp( n->right); //checks out the right side
        }
        // should the left = NULL then return nothing and continue on going into the print
    }
    Value& operator[] (int n) {
        Node *it = root;
        while( sizehelp(it) != n) {
            if( sizehelp(it->left) < n) {
                it = it->right; //if the size of the left is smaller than n change it to the right
            }
            else {
                it = it->left; // if the size is bigger move it left
            }
        }
        return it->value;
        // returns reference to the value field of the n-th Node.
        // FILL IN
    }
    BST() : count(0), root(nil) {}
    void insert( Value X ) { root = insert( X, root ); }
    Node* insert( Value X, Node* T ) {
        // The normal binary-tree insertion procedure ...
        if ( T == nil ) {
            T = new Node( X ); // the only place that T gets updated.
        } 
        else if ( X < T->value ) {
            T->left = insert( X, T->left );
        } 
        else if ( X > T->value ) {
            T->right = insert( X, T->right );
        } 
        else {
            T->value = X;
        }
        // later, rebalancing code will be installed here
        
        return T;
    }
    void remove( Value X ) { root = remove( X, root ); }
        Node* remove( Value X, Node*& T ) {
            // The normal binary-tree removal procedure ...
            // Weiss’s code is faster but way more intricate.
            if ( T != nil ) {
            if ( X > T->value ) {
                T->right = remove( X, T->right );
            } 
            else if ( X < T->value ) {
                T->left = remove( X, T->left );
            } 
            else {
                // X == T->value
                if ( T->right != nil ) {
                    Node* x = T->right;
                    while ( x->left != nil ) x = x->left;
                    T->value = x->value; // successor’s value
                    T->right = remove( T->value, T->right );
                } 
                else if ( T->left != nil ) {
                    Node* x = T->left;
                while ( x->right != nil ) x = x->right;
                    T->value = x->value; // predecessor’s value
                    T->left = remove( T->value, T->left );
                } 
                else { // *T is external
                    delete T;
                    T = nil; // the only updating of T
                }
            }
        }
    // later, rebalancing code will be installed here
    return T;
    }
    void okay( ) { 
        okay( root ); 
    }
    void okay( Node* T ) {
        // diagnostic code can be installed here
        return;
    }
}; // BST
#endif