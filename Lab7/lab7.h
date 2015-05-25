/*
    Name: Timothy Dea
    SID: 861176053
    Date: 5/24/15
*/

#ifndef __LAB7_H__
#define __LAB7_H__
#include <set>
#include <unordered_set>
#include <chrono>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <iostream>
using namespace std;
using namespace std::chrono;

void readFile(const string file, vector <string> & v){
    ifstream fin(file.c_str());
    if(!fin){
        cout << "Error opening file" << endl;
        exit(-1);
    }
    string s;
    while(getline(fin,s)){
        v.push_back(s);
    }
}

void scramble(vector <string> &v){
    for(unsigned int i=0;i<v.size();++i){
        //swap
        string temp=v.at(i);
        int pos_swapped=rand()%(v.size()-1);
        v.at(i)=v.at(pos_swapped);
        v.at(pos_swapped)=temp;
    }
}

int tree_time(vector <string> const &input, int num){
    set<string> tree;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for(int i=0;i<num;++i){
        tree.insert(input.at(i));
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    return duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
}

int tree_time_avg(vector <string> &input, int num){
    scramble(input);
    int avg=0;
    for(int i=0;i<10;++i){
        avg+=tree_time(input, num);
    }
    return avg/10.0;
}


int hash_time(vector <string> const &input, int num){
    unordered_set<string> hash;
    high_resolution_clock::time_point t1 = high_resolution_clock::now();
    for(int i=0;i<num;++i){
        hash.insert(input.at(i));
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    return duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
}

int hash_time_avg(vector <string> &input, int num){
    scramble(input);
    int avg=0;
    for(int i=0;i<10;++i){
        avg+=hash_time(input, num);
    }
    return avg/10.0;
}


#endif