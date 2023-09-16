#include<iostream>
#include<queue>
using namespace std;
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n&&arr[largest]<arr[left]){
        largest=left;
    }
    if(right<=n&&arr[largest]<arr[right]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
class heap{

    public:
        int arr[100];
        int size;
        heap(){
            arr[0]=-1;
            size=0;
        }
        void insert(int val){
            size=size+1;
            int index=size;
            arr[index]=val;
            while(index>1){
                int parentIndex=index/2;
                if(arr[parentIndex]<arr[index]){
                    swap(arr[parentIndex],arr[index]);
                    index=parentIndex;
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
            cout<<endl;
        }
        void deleteFromHeap(){
            if(size==0){
                cout<<"nothing to delete"<<endl;
                return;
            }
            //step 1 put last ele into first index
            arr[1]=arr[size];
            size--;
            //take root node to its correct position
            int i=1;
            heapify(arr,size,i);
        }
};



void heapSort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}
int main(){
 
    heap h;
    h.insert(25);
    h.insert(22);
    h.insert(23);
    h.insert(19);
    h.insert(18);
     h.insert(16);
    h.insert(20);
    h.print();
    h.deleteFromHeap();
    h.print();
    //converting an array into max heap
    int arr[6]={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){//n/2+1 se leke n tak leaf node padi hoti hh to wo heap hongi hi
        heapify(arr,n,i);
    }
    cout<<"printing the array now "<<endl;
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    //heapsort
    heapSort(arr,n);
    for(int i=1;i<n;i++){
        cout<<arr[i]<<" ";
    }


    
    cout<<endl<<"using priority queue here:"<<endl;
    //max heap
    priority_queue<int> pq;
    pq.push(4);
    pq.push(2);
    pq.push(5);
    pq.push(4);
    cout<<pq.top();//5 pada hoga top pe (max heap)

    //min heap
    priority_queue<int,vector<int>,greater<int>> minheap;

    return 0;
}