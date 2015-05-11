/*
    Name: Timothy Dea
    SID: 861176053
    Date: 5/9/15
*/

#include "lab5.h"

int main(){
    BST <int> b;
    b.insert(50);
    b.insert(20);
    b.insert(10);
    b.insert(40);
    b.insert(35);
    b.insert(45);
    b.insert(60);
    b.insert(70);
    b.minCover();
    b.displayMinCover();
    //cout << b.root->value;
    int arr[1000];
    b.findSumPath(b.root, 80, arr);
    map<int, int> m;
    b.vertSum(b.root, 0, m);
}