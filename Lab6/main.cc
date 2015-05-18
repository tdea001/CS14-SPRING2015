/*
    Name: Timothy Dea
    SID: 861176053
    Date: 5/15/15
*/

#include "selectionsort.h"
#include <list>
#include <vector>
#include <utility>

int main(){
    //tests with list
    list <int> temp;
    temp.push_back(1);
    temp.push_back(7);
    temp.push_back(3);
    temp.push_back(6);
    temp.push_back(9);
    temp.push_back(0);
    temp.push_back(4);
    cout << "pre: ";
    print(temp);
    selectionsort(temp);
    cout << "post: ";
    print(temp);
    
    //tests with empty vector
    vector <unsigned> temp1;
    cout << "pre: ";
    print(temp1);
    selectionsort(temp1);
    cout << "post: ";
    print(temp1);
    
    //tests on filled vector
    temp1.push_back(2);
    temp1.push_back(4);
    temp1.push_back(1);
    temp1.push_back(2);
    temp1.push_back(3);
    temp1.push_back(9);
    temp1.push_back(6);
    temp1.push_back(7);
    temp1.push_back(4);
    cout << "pre: ";
    print(temp1);
    selectionsort(temp1);
    cout << "post: ";
    print(temp1);
    
}