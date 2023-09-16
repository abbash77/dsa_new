#include<iostream>
using namespace std;

//7 9 8 2 9 4 3 6 
//1 6 4 8 2 5 9 4 2 5 

int main(){
    int arr1[8]={7 ,5, 8, 2 ,9 ,4 ,3 ,6};
    int arr2[10]={1, 6 ,4 ,8, 3, 5 ,9 ,43 ,2 ,12};
    int arr[10];
    int z=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<10;j++){
            if(arr1[i]==arr2[j]){
                arr[z]=arr1[i];
                z++;
            }
        }
    }
    for(int i=0;i<z;i++){
        cout<<arr[i]<<" ";
    }

    return 0;
}
    