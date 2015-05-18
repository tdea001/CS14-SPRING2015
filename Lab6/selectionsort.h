/*
    Name: Timothy Dea
    SID: 861176053
    Date: 5/15/15
*/

#ifndef __SELECTIONSORT_H__
#define __SELECTIONSORT_H__
#include <utility>
#include <iostream>
using namespace std;

template <typename L>
void print(L const &l){
    for(auto it=l.begin();it!=l.end();++it){
        cout << *it << ' ';
    }
    cout << endl;
}

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

#endif