#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
        int data;
        Node* left ;
        Node* right;
        Node(int d){
            this->data=d;
            this->right=NULL;
            this->left=NULL;
        }
};

Node* insertIntoBST(Node* root,int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d>root->data){
        root->right=insertIntoBST(root->right,d);
    }
    else{
        root->left=insertIntoBST(root->left,d);
    }
    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);//separator
    while(!q.empty()){
        Node* temp=q.front();
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

void takeInput(Node*& root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insertIntoBST(root,data);
        cin>>data;
    }
}

Node* minval(Node* root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}

Node* deleteFromBST(Node* root,int val){
    //base case
    if(root==NULL){
        return root;
    }
    if(root->data==val){
        //0 child
        if(root->left==NULL&&root->right==NULL){
            delete root;
            return NULL;
        }
        //1 child

        //left child
        if(root->left!=NULL&&root->right==NULL){
            Node* temp=root->left;
            delete root;
            return temp;
        }
        //right child
        if(root->left==NULL&&root->right!=NULL){
            Node* temp=root->right;
            delete root;
            return temp;
        }
        //2 child
        if(root->left!=NULL&&root->right!=NULL){
            int mini=minval(root->right)->data;
            root->data=mini;
            root->right=deleteFromBST(root->right,mini);
            return root;
        }
    }
    else if(root->data>val){
        root->left=deleteFromBST(root->left,val);
        return root;
    }
    else{
        root->right=deleteFromBST(root->right,val);
        return root;
    }
}

int main(){
    Node* root=NULL;
    cout<<"Enter data to create BST:";
    takeInput(root);
    cout<<endl;
    levelOrderTraversal(root);
    deleteFromBST(root,8);
    levelOrderTraversal(root);
    return 0;
}