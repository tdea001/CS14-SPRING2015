/*
    Name: Timothy Dea
    SID: 861176053
    Date: 5/24/15
*/

#include "lab7.h"

int main(){
    ofstream fout("data.txt");
    vector <string> input;
    readFile("words.txt",input);
    for(unsigned int i=5000;i<=input.size();i+=5000){
        int t_time=tree_time_avg(input, i);
        int h_time=hash_time_avg(input, i);
        fout << i << ' ' << t_time << ' ' << h_time << ' ' 
        << t_time/static_cast<double>(i) << ' ' << h_time/static_cast<double>(i) << endl;
    }
    
}