//  =============== BEGIN ASSESSMENT HEADER ================
/// Name: William Gu
/// SID: 861150295
/// Date: 4/19/2015
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <stack>
#include <stdlib.h>
#include <string>
#include <list>
#include <array>
#include "lab3.h"
using namespace std;

// 3. Implement a program to solve “Tower of Hanoi”. “Tower of Hanoi” is a 
// mathematical puzzle where we have three pegs and n disks. The objective of the 
// puzzle is to move the entire stack to another peg, obeying the following simple 
// rules:
// •Only one disk can be moved at a time.
// •Each move consists of taking the upper disk from one of the stacks and 
// placing it on top of another stack i.e. a disk can only be moved if it is the 
// uppermost disk on a stack.
// •No disk may be placed on top of a smaller disk.
// Implement recursive function
template<typename T>
void showTowerStates(int n, stack<T>& A, stack<T>& B, stack<T>& C) {
    if( n == 0) {
        cout << "No disks." << endl;
        exit(1);
    }
    if( n == 1) {
        C.push(A.top());
        cout << "Moved " << A.top() << " from peg A to C" << endl;
        A.pop();
    }
    if( A.empty() == true) {
        exit(0);
    }
    if ( A.empty() == false) {
        B.push(A.top());
        cout << "Moved " << A.top() << " from peg A to B" << endl;
        A.pop();
        if( C.empty() == true) {
            C.push(A.top());
            cout << "Moved " << A.top() << " from peg A to C" << endl;
            A.pop();
        }
        if( B.top() < C.top()) {
            C.push(B.top());
            cout << "Moved " << B.top() << " from peg B to C" << endl;
            B.pop();
            showTowerStates(n, A, B, C);
        }
        if( B.top() > C.top()) {
            int csize = C.size();
            for( int i = 0; i < csize; ++i){
                A.push(C.top());
                cout << "Moved " << C.top() << " from peg C to A" << endl;
                C.pop();
            }
            C.push(B.top());
            cout << "Moved " << B.top() << " from peg B to C" << endl;
            B.pop();
            for(int j = 0; j < csize; ++j) {
                C.push(A.top());
                cout << "Moved " << A.top() << " from peg A to C" << endl;
                A.pop();
            }
            showTowerStates(n, A, B, C);
        }
        
    }
    // Didn't notice n was the number of elements in stack A
}


// to solve the puzzle. You are to implement (Q-3) 
// with three stacks A, B and C using stack container class. 
// The output format for (Q-3) is as follows:Moved value from peg A to B
// Moved value from peg A to C
// params: A, B & C are source, auxiliary and destination stacks respectively
// n refers to number of elements in source stack A.
// value refers to value in stack




// NOTE: TESTS CAN ONLY SEEM TO BE DONE ONE AT A TIME
// MULTIPLE TESTS LEAD TO AN ERROR
int main() {
    // TwoStackFixed <int> test( 10, 5);
    // test.pushStack1(5);
    // test.pushStack1(4);
    // test.pushStack1(3);
    // test.pushStack1(2);
    // test.pushStack1(1);
    // test.pushStack1(5);
    // test.pushStack2(4);
    // test.pushStack2(3);
    // test.pushStack2(2);
    // test.pushStack2(1);
    
    // // test.pushStack2(5); // test for too large of a stack2
    // // test.pushStack1(5); //test for too large of a stack1
    
    // test.display();
    
    // TwoStackFixed <char> tests( 5, 3);
    // tests.pushStack1('H');
    
    // tests.display();
    
    // TwoStackOptimal <int> otest( 10);
    // otest.pushFlexStack1(5);
    // otest.pushFlexStack1(4);
    // otest.pushFlexStack1(3);
    // otest.pushFlexStack1(2);
    // otest.pushFlexStack1(1);
    // otest.pushFlexStack1(5);
    // otest.pushFlexStack2(4);
    // otest.pushFlexStack2(3);
    // otest.pushFlexStack2(2);
    // otest.pushFlexStack2(1);
    // otest.display();
    
    // stack <int> A;
    // stack <int> B;
    // stack <int> C;
    // for( int i = 0; i < 5; ++i) {
    //     A.push(5-i);
    // }
    
    // int n = 5;
    // showTowerStates(n, A, B, C);
    return 0;
}