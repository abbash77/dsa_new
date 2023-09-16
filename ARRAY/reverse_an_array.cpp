#include<iostream>
using namespace std;

// 1 2 3 4 5 6 7 8
// 8 7 6 5 4 3 2 1 
void swap(int &n1,int &n2){
    int temp=n1;
    n1=n2;
    n2=temp;
}

int main(){
    int arr[8]={1,2,3,4,5,6,7,8};
    for(int i=0;i<8/2;i++){
        swap(arr[i],arr[8-1-i]);
    }
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}