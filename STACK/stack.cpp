#include<iostream>
using namespace std;

class stack{
    public:
        int *arr;
        int top;
        int size;
        stack(int size){
            this->size=size;
            arr=new int[size];
            top=-1;
        }
        void push(int element){
            if(size-top>1){//top<size-1
                top++;
                arr[top]=element;
            }
            else{
                cout<<"stack overflow"<<endl;
            }
        }
        void pop(){
            if(top>=0){
                top--;
            }
            else{
                cout<<"stack underflow"<<endl;
            }
            
        }
        int peek(){
            if(top>=0){
                return arr[top];
            }
            else{
                cout<<"stack is empty"<<endl;
                return -1;
            }
            
        }
        bool isEmpty(){
            if(top==-1){
                return true;
            }
            else{
                return false;
            }
        }
};

int main(){
    stack st(5);
    st.push(22);
    st.push(43);
    st.push(54);
    int a=st.peek();
    cout<<a;
    st.pop();
    cout<<st.peek();
    if(st.isEmpty()){
        cout<<"stack is empty";
    }
    else{
        cout<<"stack is non empty";
    }

    return 0;
}