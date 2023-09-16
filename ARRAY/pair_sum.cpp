#include<iostream>
using namespace std;

// 1 3 -1 5 -3 8 9 -5 7 4
// sum=4
// find pairs ex (1,3)

int main(){
    int arr[10]={1 ,3 ,-1 ,5 ,-3 ,8 ,9 ,-5 ,7,4}; 
    int sum=4;
    for(int i=0;i<10-1;i++){
        for(int j=0+i+1;j<10;j++){
            if(arr[i]+arr[j]==sum){
                cout<<"("<<arr[i]<<","<<arr[j]<<")"<<",";
            }
        }
    } 

    return 0;
}