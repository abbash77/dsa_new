#include<iostream>
#include<algorithm>
using namespace std;

bool should_i_swap(int a,int b){//comparator function
    if(a<b) return true;
    return false;
}


int main(){
    int arr[6]={1,5,3,2,9,7};
    sort(arr,arr+6,should_i_swap);
    // for(int i=0;i<6;i++){
    //     cout<<arr[i]<<" ";
    // }

    string a="330";
    string b="303";

    if(a<b){
        cout<<"a";
    }
    else{
        cout<<"b";
    }


    return 0;
}