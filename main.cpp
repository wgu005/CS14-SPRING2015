//  =============== BEGIN ASSESSMENT HEADER ================
/// Name: William Gu
/// SID: 861150295
/// Date: 4/19/2015
//  ================== END ASSESSMENT HEADER ===============
#include <iostream>
#include <forward_list>
#include "lab2.h"
using namespace std;
// 1. Write  a  recursive  function int  primeCount(  forward_list<int>  lst  )
// to  count  the  number  of prime   numbers   in   a   numerical   singly   linked   list   and   implement   a   helper   function 
// bool isPrime( int i ) to judge whether an integer is a prime or not.

bool isPrime(int i) {
    bool a = false;
    if( i == 2) { // special case when the number is 2
        return true;
    }
    for(int j = 2; j < i; ++j) { // moving j until its equal to i
        if (i % j == 0 &&  j != i) { //testing if i is divisible by j and if j and i are the same
            return false;
        }
        return true;
    }
    
    return a;
}

int Count (forward_list<int> lst, int cnt) {
    if( lst.empty() == true) {
        return cnt;
    }
    if( isPrime(lst.front()) == true) {
        cnt = cnt + 1;    
    }
    lst.pop_front();
    return Count( lst, cnt);
}

int primeCount( forward_list<int> lst) {
    int cnt = 0; //return value for this function
    
    if( lst.empty() == true) {
        return 0;
    }
    // forward_list<int>::iterator it; // the itertor to search through the list
    // it = lst.begin();
    // while(it != lst.end()) { // going through the entire list
    //     if( isPrime(*it) == true ) { // this was non recursive
    //         cnt = cnt + 1; 
    //     }
    //     ++it;
    // }
    

    return Count( lst, cnt);  
}
// 3. Write a function void listCopy( forward_list <Type> L, forward_list&<Type>&P ) to copy a singly linked list L into a second singly linked list P in reverse 
// order by only traversing L once which means the reverse of list L is to be concatenated onto the back of list P.
template <typename Type>
void listCopy( forward_list <Type> L, forward_list <Type> &P) {
    L.reverse();
    P.merge(L);
    while( P.empty() == false) {
        cout << P.front() << endl;
        P.pop_front();
    }
    
    
}

// You are given a singly linked list L of a type, and another singly linked list P containing integers sorted   in   ascending   order.   Write   a   function 
// void printLots (forward_list <Type> L, forward_list <int> P )to print the elements in L that are in positions specified by P. For instance, 
// if P=1,3,4,6, the elements in positions 1,3,4, and 6 in L are printed
template <typename Type>
void printLots( forward_list<Type> L, forward_list<int> P) {
    
    while(P.empty() == false) {
        auto it = L.begin();
        for(int i = 0; i < P.front(); ++i) {
            ++it;
        }
        cout << *it;
        P.pop_front();
    }
    
}







int main() {
    // // Part1's test
    // forward_list<int> list;
    
    
    // for(int i = 0; i < 5; ++i) {
    //     list.push_front(i);
    // }
    // cout << primeCount(list) << endl;
    // //end part 1 test
    
    // //Part two's test
    // List myList;
    // myList.push_front(7);
    // myList.push_front(5);
    // myList.push_front(6);
    // myList.print();
    // cout << endl;
    // myList.elementSwap(0);
    // myList.print();
    // myList.elementSwap(1);
    // myList.print();
    // myList.elementSwap(2);
    // cout << endl;
    // //end part 2
    
    // //Part 3 test begin
    // forward_list<int> z;
    // z.push_front(5);
    // z.push_front(6);
    // z.push_front(7);
    // z.push_front(8);
    // forward_list<int> a;
    // a.push_front(1);
    // a.push_front(2);
    // a.push_front(0);
    // a.push_front(3);
    // listCopy(z, a );
    // //Part 3 test end
    // //Test part 4
    // forward_list<int> z;
    // z.push_front(5);
    // z.push_front(6);
    // z.push_front(7);
    // z.push_front(8);
    // forward_list<int> a;
    // a.push_front(1);
    // a.push_front(2);
    // a.push_front(0);
    // a.push_front(3);
    // printLots( z, a);
    // cout << endl;
    // // end test 4
    
    return 0;
}

