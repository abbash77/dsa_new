#include<iostream>
using namespace std;
void merge(int arr[],int s,int e){
    int mid=(s+e)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int *first=new int[len1];
    int *second=new int[len2];
    int mainArrayindex=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[mainArrayindex++];
    }
    mainArrayindex=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[mainArrayindex++];
    }
    //merge 2 sorted arrays
    int index1=0;
    int index2=0;
    mainArrayindex= s;
    while(index1<len1&&index2<len2){
        if(first[index1]<second[index2]){
            arr[mainArrayindex++]=first[index1++];
        }
        else{
            arr[mainArrayindex++]=second[index2++];

        }
    }
    while(index1<len1){
            arr[mainArrayindex++]=first[index1++];

    }
     while(index2<len2){
            arr[mainArrayindex++]=second[index2++];

    }
    delete []first;
    delete []second;

}

void mergeSort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int mid=(s+e)/2;
    //left part sort krna hh
    mergeSort(arr,s,mid);
    //right part sort
    mergeSort(arr,mid+1,e);
    //merge
    merge(arr,s,e);
}

int main(){
    int arr[5]={2,5,1,6,9};
    int n=5;
    mergeSort(arr,0,n-1);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}


//code studio

// void merge(int s,int mid,int e,vector<int>& arr){
//     int arr1S=s;
//     int arr1E=mid;
//     int arr2S=mid+1;
//     int arr2E=e;
//     vector<int> ans;
//     while(arr1S<=arr1E&&arr2S<=arr2E){
//         if(arr[arr1S]>arr[arr2S]){
//             ans.push_back(arr[arr2S]);
//             arr2S++;
//         }
//         else{
//             ans.push_back(arr[arr1S]);
//             arr1S++;
//         }
//     }
//     while(arr1S<=arr1E){
//         ans.push_back(arr[arr1S++]);
//     }
//     while(arr2S<=arr2E){
//         ans.push_back(arr[arr2S++]);
//     }
//     int j=0;
//     for(int i=s;i<=e;i++){
//         arr[i]=ans[j];
//         j++;
//     }
// }
// void recur(int s,int e,vector<int> &arr){
//     if(s>=e){
//         return;
//     }
//     int mid=(s+e)/2;
//     recur(s,mid,arr);
//     recur(mid+1,e,arr);
//     merge(s,mid,e,arr);
// }
// void mergeSort(vector < int > & arr, int n) {
//     // Write your code here.
//     recur(0,n-1,arr);
// }