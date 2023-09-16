#include<iostream>
#include<vector>
using namespace std;

class Heap{
    public:
        int index;
        int arr[100];
        int size;
        Heap(){
            size=0;
            index=-1;
        }
        void insertion(int input){
            size++;
            index++;
            arr[index]=input;
            int x=index;
            
            while(x>0){
                int parentIndex=(x-1)/2;
                if(arr[parentIndex]<arr[x]){
                    swap(arr[parentIndex],arr[x]);
                    x=parentIndex;
                }
                else{
                    break;
                }
            }
            
        }
        void print(){
            for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
            }
        }
};

int main(){
    Heap H;
    vector<int> v{18,22,25,16,8,33};
    for(int i=0;i<v.size();i++){
        H.insertion(v[i]);
    }
    H.print();


    return 0;
}