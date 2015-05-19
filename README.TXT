part a. Can you give a reason why your selection sort is or is not stable?
    
a.) If I had an list containing 3, 3, 2, and 4. The variables in slot 0 and 2 would switch meaning that
the 3 that use to be before the other 3 is now behind it
    
    
    
template<typename L>
void selectionsort(L &l) {
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
            // if(min == *it) {
            //     if(location == minlocation) {
                    
            //     }
            //     else {
                    
            //     }
            // }
            if( min > *it) {
                min = *it;
                swap2 = it;
            }
            
            location = location + 1;
        }
        *swap2 = *swap1;
        *swap1 = min;
        display(l);
}
template<typename L>
void display(L &l) {
    
        for( typename L::iterator it = l.begin(); it != l.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
}


All I need to do is go through it once to show that the value in position 0 switches with the value in position 2. Then the value in position one is before the new position 2
it won't switch those two meaning the value that use to be before is now after.