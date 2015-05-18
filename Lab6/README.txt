a) The selection sort is not stable because after a swap the relative ordering 
    is not maintained. The selection sort function would be stable if the minimum 
    element was pushed to the front of the container and the rest of the elements
    swapped the relative ordering is not maintained.
    
b) if given the input vector of: 4, 7, 2, 4, 9, 1 
    and with the function: 
        template <typename L>
        void selectionsort(L &l){
            for(auto it=l.begin();it!=l.end();++it){
                auto min=it;
                auto it1=it;
                ++it1;
                for(; it1!=l.end();++it1){
                    if(*it1<*min) min=it1;
                }
                if(*min!=*it) swap(*min,*it);
            }
        }
    
    in the first swap, 1 will be swapped with 4
    then, the order would be 1, 7, 2, 4, 9, 4
    this does not maintain the relative order, thus the selection sort is not stable