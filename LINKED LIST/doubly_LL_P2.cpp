#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
    ~Node(){
        int val=this->data;
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory freed for node with data "<<val<<endl;
    }
};
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int getLength(Node *head)
{
    int len = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}
void insertAtHead(Node *&head, int d,Node* &tail)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node *&tail, int d,Node* &head)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
        head = temp;

    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertAtPos(Node *&head, int pos, int d, Node *&tail)
{
    if (pos == 1)
    {
        insertAtHead(head, d,tail);
        return;
    }
    else
    {
        Node *temp = new Node(d);
        Node *dummy = head;
        int cnt = 1;
        while (cnt < pos - 1)
        {
            dummy = dummy->next;
            cnt++;
        }
        if (dummy->next == NULL)
        { // inserting at last position
            insertAtTail(tail, d,head);
            return;
        }
        temp->next = dummy->next;
        dummy->next->prev = temp;
        dummy->next = temp;
        temp->prev = dummy;
    }
}
void deleteNode(int pos,Node* &head){
    if(pos==1){//deleting head node
        Node* temp=head;
        head=temp->next;
        temp->next->prev=NULL;
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
        curr->prev=NULL;
        prev->next=curr->next;
        curr->next=NULL;
        delete curr;
    }
}
int main()
{
    // Node *node1 = new Node(10);
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, 9,tail);
    insertAtTail(tail, 25,head);
    insertAtPos(head, 2, 77, tail);
    //9 77 25
    deleteNode(1,head);
    print(head);
    return 0;
}