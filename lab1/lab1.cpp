#include <list>
#include <iostream>
#include <sstream>
using namespace std;

void mergeList(list<int>& list1, list<int>& list2){
    list<int>::iterator i=list1.begin();
    for(list<int>::iterator j=list2.begin(); j!=list2.end(); ++j){
        if(i!=list1.end()){
            list2.insert(j, *i);
            i++;
        }
    }
    if(i!=list1.end()){
        while(i!=list1.end()){
            list2.push_back(*i);
            ++i;
        }
    }
}

void mergeSortList(list<int>& list1, list<int>& list2){
    list2.merge(list1);
}

void rotate(list <int>& l, int n){
    list<int>::iterator i=l.begin();
    for(int j=0;j<n;++j){
        l.push_back(*i);
        i++;
    }
    for(int i=0;i<n;++i){
        l.pop_front();
    }
}

int main(){
    int x;
    list <int> l1;
    list <int> l2;
    string input;
    getline(cin, input);
    stringstream s(input);
    while(s >> x){
        l1.push_back(x);
    }
    s.clear();
    getline(cin, input);
    s.str(input);
    while(s >> x){
        l2.push_back(x);
    }
    mergeList(l1, l2);
    for(list<int>::iterator i=l2.begin(); i!=l2.end();++i){
        cout << *i << ' ';
    }
    cout << endl;
}