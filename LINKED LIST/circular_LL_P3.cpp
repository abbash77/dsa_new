#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int d){
            this->data=d;
            this->next=NULL;
        }
        ~Node(){
            int val=this->data;
            if(this->next!=NULL){
                delete next;
                this->next=NULL;
            }
            cout<<" memory is freed for node with data "<<val<<endl;
        }
};

void insertNode(Node* &tail,int d,int element){
    //assuming that the element is present in the list
    //empty list 
    if(tail==NULL){
        Node* newNode=new Node(d);
        tail=newNode;
        newNode->next=newNode;
    }
    else{
        //non-empty-list
        Node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        //element found ,curr is representing element wala node
        Node* temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}
void print(Node* tail){
    Node* temp=tail;
    if(tail==NULL){
        cout<<"list is empty"<<endl;
        return;
    }
   do{
       cout<<tail->data<<" ";
       tail=tail->next;

   }while(tail!=temp);

}
void deleteNode(Node* &tail,int value){
    //empty list
    if(tail==NULL){
        cout<<"list is empty plzz check again"<<endl;
    }
    else{
        //assuming that value is present in the list
        Node* prev=tail;
        Node* curr=prev->next;
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        //1 node LL
        if(curr==prev){
            tail=NULL;
        }
        //>=2 node LL
        if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;

    }
}

int main()
{
    Node * tail=NULL;
    insertNode(tail,5,3);//starting me empty hh to 3(element) bhejne ka koi matlab nhi hh par
    //bhejna padega
    insertNode(tail,8,5);
    insertNode(tail,10,8);
    insertNode(tail,6,5);
    //5 6 8 10
    deleteNode(tail,8);
    //5 6 10
    print(tail);

    return 0;
}
