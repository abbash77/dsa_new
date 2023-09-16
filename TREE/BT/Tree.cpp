#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
        int data;
        node* left;
        node* right;
        node(int d){
            this->left=NULL;
            this->right=NULL;
            this->data=d;
        }
};

node* buildTree(node* root){
    cout<<"enter the data ";
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"enter data for inserting in left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"enter data for inserting in right of "<<data<<endl;
    root->right=buildTree(root->right);
    return root;
}
void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);//separator
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        if(temp==NULL){//purana level complete ho chuka hh
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);//queue still has some child nodes
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        
    }
}
void preOrder(node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrder(root->left);
    preOrder(root->right);

}
void inOrder(node* root){
    if(root==NULL){
        return;
    }
 
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);

}
void postOrder(node* root){
    if(root==NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";

}
node* buileFromLevelOrder(){
    queue<node* > q;
    int data;
    cout<<"Enter data for root "<<endl;
    cin>>data;
    node* root=new node(data);
    q.push(root);
    while(!q.empty()){
        node* temp=q.front();
        q.pop();
        int leftdata;
        cout<<"Enter left node for: "<<temp->data<<endl;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left=new node(leftdata);
            q.push(temp->left);
        }
        int rightdata;
        cout<<"Enter right node for: "<<temp->data<<endl;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right=new node(rightdata);
            q.push(temp->right);
        }
    }
    return root;
}
int main(){
    node* root=NULL;
    root=buildTree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    levelOrderTraversal(root);
    // inOrder(root);
    // root=buileFromLevelOrder();
    // levelOrderTraversal(root);
    

    return 0;
}