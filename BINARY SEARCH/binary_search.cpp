#include<iostream>
using namespace std;
int binarySearch(int arr[],int size,int n){
    int start=0;
    int end=size-1;
    int mid=(start+end)/2;
    while(start<=end){
        if(arr[mid]==n){
            return mid;
        }
        //left jaana hh
        if(arr[mid]>n){
            end=mid-1;
        }
        else{
            start=mid+1;
        }
        mid=(start+end)/2;
    }
    return -1;

}
int main(){
    int arr[6]={11,29,38,39,56,64};
    int index=binarySearch(arr,6,56);
    cout<<index;
    return 0;
}