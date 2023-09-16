#include<iostream>
using namespace std;

void Heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n&&arr[left]>arr[largest]){
        largest=left;
    }
    if(right<=n&&arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        Heapify(arr,n,largest);
    }
}

class Heap{
    public:
        int arr[100];
        int size;

        Heap(){
            size=0;
            arr[0]=-1;
        }
        void insert(int val){
            size++;
            int idx=size;
            arr[idx]=val;
            while(idx>1){
                int pidx=idx/2;
                if(arr[pidx]<arr[idx]){
                    swap(arr[pidx],arr[idx]);
                    idx=pidx;
                }
                else{
                    return;
                }
            }
        }
        void print(){
            for(int i=1;i<=size;i++){
                cout<<arr[i]<<" ";
            }
        }
        void del(){
            arr[1]=arr[size];
            size--;
            Heapify(arr,size,1);
        }
};


int main(){
    Heap H;
    H.insert(22);
    H.insert(32);
    H.insert(12);
    H.insert(43);
    H.insert(14);
    H.insert(8);
    H.insert(19);
    H.print();


    return 0;
}