#include<iostream>
using namespace std;

void binarySearch(int arr[],int size,int n){
    int start=0;
    int end=size-1;
    int mid=(start+end)/2;
    int max=-1;
    int min=-1;
    while(start<=end){
        if(arr[mid]==n){
            min=mid;
            max=mid;
            while(arr[min-1]==n){
                min--;
            }
            while(arr[max+1]==n){
                max++;
            }
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
    cout<<"max:"<<max<<" min:"<<min<<endl;

}

int main(){
    int arr[16]={0,0,0,1,1,5,5,5,7,9,9,9,9,14,14,14};
    binarySearch(arr,16,14);
    return 0;
}