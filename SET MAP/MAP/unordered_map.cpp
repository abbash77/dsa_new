#include<iostream>
#include<unordered_map>
using namespace std;


int main(){
    unordered_map<int,string> m;
    m[1]="abc";
    m[5]="jaj";
    m[9]="aja";
    m[4]="abcd";
    /*
    1 abc
    5 jaj
    9 aja
    4 abcd
    not in sorted order time complexity is O(1) avg time complexity;
    */
   //acess find erase sab O(1);
   //*******************************************************
   //ordered me kchbhi daal skte the jaise map<pair<int,int>,string > m
//    lets see in unordered_map now

    // unordered_map<pair<int,int>,string > m;//error aayega yaha pe


    return 0;
}