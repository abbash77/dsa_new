#include<iostream>
using namespace std;



int main(){

    int arr[10]={5,4,7,8,2,1,5,7,8,3};
    int arr2[100]={0};
    for(int i=0;i<10;i++){
        arr2[arr[i]]=arr2[arr[i]]+1;
    }
    //unique
    for(int i=0;i<100;i++){
        if(arr2[i]==1){
            cout<<i<<" ";
        }
    }
    cout<<endl;
    //duplicate
    for(int i=0;i<100;i++){
        if(arr2[i]>1){
            cout<<i<<" ";
        }
    }


    return 0;
}