#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node(int data){
            this->data=data;
            this->next=NULL;
        }
        ~Node(){
            int value=this->data;
            //memort free karane ka code
            if(this->next!=NULL){
                delete next;
                this->next=NULL;
            }
            cout<<"memory is freed for node with data "<<value<<endl;
        }
};

void insertAtHead(Node* &head,int d){
    Node *temp=new Node(d);
    temp->next=head;
    head=temp;
}
void insertAtTail(Node* &tail,int d){
    Node *temp=new Node(d);
    tail->next=temp;
    tail=tail->next;
}
void insertInMiddile(Node* &head,int pos,int d,Node* &tail){
    //insert at start
    if(pos==1){
        insertAtHead(head,d);
        return;
    }

    Node* temp=new Node(d);
    Node* dummy=head;
    int cnt=1;
    while(cnt<pos-1){
        dummy=dummy->next;
        cnt++;
    }
    if(dummy->next==NULL){//inserting at last position
        insertAtTail(tail,d);
        return;
    }
    temp->next=dummy->next;
    dummy->next=temp;

}

void print(Node* &head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
void deleteNode(int pos,Node* &head){
    if(pos==1){//deleting head node
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;//memory free krwa rhe

    }  
    else{
        //deleting any middle node or end node                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
        Node* curr=head;
        Node* prev=NULL;
        int cnt=1;
        while(cnt<pos){
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
int main(){

    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    insertAtHead(head,12);
    insertAtTail(tail,15);
    insertInMiddile(head,3,33,tail);
    insertInMiddile(head,5,323,tail);
    deleteNode(1,head);
    deleteNode(4,head);
    print(head);


    return 0;
}