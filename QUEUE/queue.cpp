#include<iostream>
using namespace std;

class queue{

    int front;
    int rear;
    int size;
    int* arr;
    public:
        queue(int size){
            this->size=size;
            front=0;
            rear=0;
            arr=new int[size];
        }
        void enqueue(int data){
            if(rear==size){
                cout<<"queue is full";
            }
            else{
                arr[rear]=data;
                rear++;
            }
        }
        int dequeue(){
            if(rear==front){
                cout<<"empty";
                return -1;
            }
            else{
                int ans=arr[front];
                arr[front]=-1;
                front++;
                if(front==rear){
                    front=0;
                    rear=0;
                }
                return ans;
            }
        }
        bool empty(){
            if(front==rear){
                return true;
            }
            return false;
        }
        int frontele(){
            if(front==rear){
                return -1;
            }
            else{
                return arr[front];
            }
        }



};

int main(){
    queue q(5);
    q.enqueue(1);
    q.empty();
    int a=q.frontele();
    cout<<a<<" ";
    q.enqueue(2);
    q.empty();
    a=q.frontele();
    cout<<a<<" ";
    q.enqueue(3);
    q.empty();
    a=q.frontele();
    cout<<a<<" ";
    q.enqueue(4);
    q.empty();
    a=q.frontele();
    cout<<a<<" ";
    q.enqueue(5);
    q.empty();
    a=q.frontele();
    cout<<a<<" ";
    q.dequeue();
    q.enqueue(6);

    return 0;
}