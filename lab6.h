#include <iostream>
#include <list>
#include <vector> 
#include <utility> 
using namespace std;

template<typename L>
void selectionsort(L &l) {
    
    for(int i = 0; i < l.size(); ++i) {
        auto min = 0;
        int minlocation = 0;
        int location = 0;
        
        typename L::iterator swap1 = l.begin();
        
        for(int j = 0; j < i; ++j) {
            ++swap1;
            location = location + 1;
            
        }
        min = *swap1;
        minlocation = location;
        typename L::iterator swap2 = swap1;
        for( typename L::iterator it = swap1; it != l.end(); ++it) {
            if(min == *it) {
                if(location == minlocation) {
                    
                }
                else {
                    
                }
            }
            if( min > *it) {
                min = *it;
                swap2 = it;
            }
            
            location = location + 1;
        }
        *swap2 = *swap1;
        *swap1 = min;


    }

}

template<typename L>
void display(L &l) {
    
        for( typename L::iterator it = l.begin(); it != l.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
}





// template<typename L>
// void display( list <L> &l) {
//     while(l.empty() == false) {
//         cout << "(" << l.front().first << ", " << l.front().second  << ")"<< endl;
//         l.pop_front();
//     }


    

// }
