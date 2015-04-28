#ifndef LAB3_H
#define LAB3_H
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <string>
#include <list>
#include <array>
#include "lab3.h"
using namespace std;
template<typename T>
class TwoStackFixed {
    // 1.) Implement a class TwoStackFixed,instances of which represent two stacks.
    // Your implementation should consider following:
    // ·Two stacks are implemented using only one array. Size of array is user 
    // driven.
    // ·Stacks are allocated 
    // fixed spacemin array. Array does not grow or shrink with growing/shrinking stacks.
    // ·Bottom of stacks being the ends of array, stacks grow in opposite directions.
    // ·Stack overflow and underflow condition must be handled.Implement the following:

    private:
    int* arr;
    int max1;
    int max2;
    stack<T> stack1;
    stack<T> stack2;
    int sz;
    public:
    
    
    TwoStackFixed(int size, int maxtop);
    void pushStack1(T value);
    void pushStack2(T value);
    T popStack1();
    T popStack2();
    bool isFullStack1();
    bool isFullStack2();
    bool isEmptyStack1();
    bool isEmptyStack2();
    void display();
};
// TwoStackFixed(int size, int maxtop );constructor that constructs array 
// of size and constructs empty stacks with maxtop specifying the partition for stacks. 
// HOW DOES USER SPECIFY THE FIXED AMOUNT OF SPACE FOR EACH STACK?

template<typename T>
TwoStackFixed<T>::TwoStackFixed( int size, int maxtop) {
    if( maxtop >= size) {
        cout << "Maxtop is too large" << endl;
        exit(1);
    }
    max1 = maxtop + 1;
    max2 = size - maxtop;
    sz = size;
    arr = new int( size);
    // for( int i = 0; i < sz; ++i) {
    //     arr[i] = 0;
    // }
}

//Display Function
template<typename T>
void TwoStackFixed<T>::display() {
    int size1 = stack1.size();
    int size2 = stack2.size();
    for( int i = 0; i < max1 + 1; ++i) {
        if(isEmptyStack1() == false) {
            arr[i] = stack1.top();
            stack1.pop();
        }
    }
    for( int i = 1; i < max2; ++i) {
        if(isEmptyStack2() == false) {
            arr[sz - i] = stack2.top();
            stack2.pop();
        }
    }
    
    for( int i = 0; i < sz; ++i) {
        if( i < size1 ) {
                cout << arr[i] << endl;
            }
        else if( i < max1) {
            cout << " " << endl; // << i;
        }
        else if( i < sz - size2) {
            cout << " " << endl;
            }
        else if( i < sz) {
            cout << arr[i] << endl;
            
        }

    }
    // cout << size2;
    // cout << "other test" << endl;
    // cout << max1 << endl;
    // cout << max2 << endl;
    // cout << sz << endl;
}

// // void pushStack1(T value);
// // to push element into first stack.
template<typename T>
void TwoStackFixed<T>::pushStack1(T value) {
    if(isFullStack1() == false) {
        stack1.push(value);
    }
    else {
        cout << "Stack1 is too large" << endl;
        exit(1);
    }
    
}

// // void pushStack2(T value);
// // to push element into second stack.
template<typename T>
void TwoStackFixed<T>::pushStack2(T value) {
    if(isFullStack2() == false) {
        stack2.push(value);
    }
    else {
        cout << "Stack2 is too large" << endl;
        exit(1);
    }
}

// // T popStack1();
// // to pop element from first stack.
template<typename T>
T TwoStackFixed<T>::popStack1() {
    T value;
    value = stack1.top();
    if( isEmptyStack1() == true) {
        cout << "Stack1 is already empty" << endl;
        exit(1);
    }
    stack1.pop();
    return value;
}

// // T popStack2();
// // to pop element from second stack.
template<typename T> 
T TwoStackFixed<T>::popStack2(){
    T value;
    value = stack2.top();
    if( isEmptyStack2() == true) {
        cout << "Stack2 is already empty" << endl;
        exit(1);
    }
    stack2.pop();
    return value;
}

// // bool isFullStack1();
// // helper function to check whether first stack is full.
template<typename T> 
bool TwoStackFixed<T>::isFullStack1() {
    if(stack1.size() < max1) {
        return false;
    }
    else {
        return true;
    }
}

// // bool isFullStack2();
// // helper function to check whether second stack is full.
template<typename T> 
bool TwoStackFixed<T>::isFullStack2() {
    if(stack2.size() < max2 - 1) {
        return false;
    }
    else {
        return true;
    }
}

// // bool isEmptyStack1();
// // helper function to check whether first stack is empty.
template<typename T> 
bool TwoStackFixed<T>::isEmptyStack1() {
    if(stack1.empty() == true) {
        return true;
    }
    else {
        return false;
    }
}

// // bool isEmptyStack2();
// // helper function to check whether second stack is empty.
// // MUST OVERFLOW/UNDERFLOW BE HANDLED IN THIS CASE AS WELL AS THE NEXT? IF SO, WE SHOULD SPECIFY. 
// // (mentioned in question)
template<typename T> 
bool TwoStackFixed<T>::isEmptyStack2() {
    if(stack2.empty() == true) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
class TwoStackOptimal {
    private:
    int* arr;
    int max1;
    int max2;
    stack<T> stack1;
    stack<T> stack2;
    int sz;
    public:
    TwoStackOptimal(int size);
    void pushFlexStack1(T value);
    void pushFlexStack2(T value);
    T popFlexStack1();
    T popFlexStack2();
    bool isFullStack1();
    bool isFullStack2();
    bool isEmptyStack1();
    bool isEmptyStack2();
    void display();
};
//constructor that constructs array of size and constructs empty stacks.
template<typename T>
TwoStackOptimal<T>::TwoStackOptimal(int size) {
    sz = size;
    arr = new int( size);
}

// Implement a class TwoStackOptimal instances of which represent two stacks. 
// Your implementation consider following features:
// Two stacks are implemented using only one array. Size of array is user driven.
// ·Stacks are allocated flexible space in array. Array does not grow or shrink 
// with growing/shrinking stacks, but Stack boundaries in array are not fixed/pre
// -determined.
// ·Bottom of stacks being the ends of array, stacks grow in opposite directions.
// ·Stack overflow and underflow condition must be handled.Implement the following:

template<typename T>
void TwoStackOptimal<T>::display() {
    int size1 = stack1.size();
    int size2 = stack2.size();
    for( int i = 0; i < size1; ++i) {
        if(isEmptyStack1() == false) {
            arr[i] = stack1.top();
            stack1.pop();
        }
    }
    for( int i = 1; i < size2 + 1; ++i) {
        if(isEmptyStack2() == false) {
            arr[sz - i] = stack2.top();
            stack2.pop();
        }
    }
    
    for( int i = 0; i < sz; ++i) {
        if( i < size1 ) {
                cout << arr[i] << endl;
            }
        else if( i < sz - size2) {
            cout << " " << endl; // << i;
        }
        else if( i < sz) {
            cout << arr[i] << endl;
            
        }

    }
    cout << size1 << endl;
    cout << size2 << endl;
}
// to push element into first stack.
template<typename T>
void TwoStackOptimal<T>::pushFlexStack1(T value) {
    if(isFullStack1() == false) {
        stack1.push(value);
    }
    else {
        cout << "Stack1 is too large" << endl;
        exit(1);
    }
}

// to push element into second stack.
template<typename T>
void TwoStackOptimal<T>::pushFlexStack2(T value) {
    if(isFullStack2() == false) {
        stack2.push(value);
    }
    else {
        cout << "Stack2 is too large" << endl;
        exit(1);
    }
}


// to pop element into first stack.
template<typename T>
T TwoStackOptimal<T>::popFlexStack1() {
    T value;
    value = stack1.top();
    if( isEmptyStack1() == true) {
        cout << "Stack1 is already empty" << endl;
        exit(1);
    }
    stack1.pop();
    return value;
}


// to pop element from second stack.
template<typename T>
T TwoStackOptimal<T>::popFlexStack2() {
    T value;
    value = stack2.top();
    if( isEmptyStack2() == true) {
        cout << "Stack2 is already empty" << endl;
        exit(1);
    }
    stack2.pop();
    return value;
}


// helper function to check whether first stack is full.
template<typename T>
bool TwoStackOptimal<T>::isFullStack1() {
    if(stack2.size() + stack1.size() < sz) {
        return false;
    }
    else {
        return true;
    }
}


// helper function to check whether second stack is full.
template<typename T>
bool TwoStackOptimal<T>::isFullStack2() {
    if(stack2.size() + stack1.size() < sz) {
        return false;
    }
    else {
        return true;
    }
}



// helper function to check whether first stack is empty.
template<typename T>
bool TwoStackOptimal<T>::isEmptyStack1() {
    if(stack1.empty() == true) {
        return true;
    }
    else {
        return false;
    }
}


// helper function to check whether second stack is empty.
template<typename T>
bool TwoStackOptimal<T>::isEmptyStack2() {
    if(stack2.empty() == true) {
        return true;
    }
    else {
        return false;
    }
}

#endif /* LAB3_H */