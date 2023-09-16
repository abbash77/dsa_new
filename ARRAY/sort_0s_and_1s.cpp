#include<iostream>
using namespace std;

//0 1 0 1 0 0 1 1 1 0
//0 0 0 0 0 1 1 1 1 1
int main(){
    int arr[10]={0 ,1 ,0 ,1 ,1,1};
    int left=0;
    int right=6-1;
    while(left<right){
        while(arr[left]==0&&left<right){
            left++;
        }
        while(arr[right]==1&&left<right){
            right--;
        }
        if(left<right){
            arr[left]=0;
            arr[right]=1;
            left++;
            right--;
        }
    }
    for(int i=0;i<6;i++){
        cout<<arr[i]<<" ";
    }


    return 0;
}