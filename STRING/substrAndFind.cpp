#include<iostream>
#include<string>
using namespace std;

int main(){
    string s="abbas:haider";
    cout<<s.substr(6,6)<<endl;//from position or index 6 give me values
    //output == haider
    //substr return string
    //s.find() find the position or index of a character
    cout<<s.find(':')<<endl;
    //output 5
    int idx=s.find(':');

    cout<<s.substr(idx+1,6)<<endl;
    //output haider
    cout<<s.substr(2);//this means from index to (2 to last)
    //output bas:haider


    return 0;
}