#include<iostream>
using namespace std;

class trieNode{
    public:
        char data;
        trieNode* children[26];
        bool isTerminal;
        trieNode(char ch){
            data=ch;
            for(int i=0;i<26;i++){
                children[i]==NULL;
            }
            isTerminal=false;
        }
};
class trie{
    public:
        trieNode* root;
        trie(){
            root=new trieNode('\0');
        }
        void insertUtil(trieNode* root,string word){
            //base case
            if(word.length()==0){
                root->isTerminal=true;//last character ko terminal node set kr rhe
                return;
            }
            //assumption word will be in caps
            int index=word[0] - 'A';
            trieNode* child;
            if(root->children[index]!=NULL){//present to bas aage badh jao
                child=root->children[index];
            }
            else{//absent hh to naya bnake aage badh jao
                child=new trieNode(word[0]);
                root->children[index]=child;
            }
            //recursion
            insertUtil(child,word.substr(1));//word ka first character chodke aage badh jao

        }
        void insertWord(string word){
            insertUtil(root,word);
        }
        bool searchUtil(trieNode* root,string word){
            if(word.length()==0){
                return root->isTerminal;
            }
            int index=word[0] - 'A';
            trieNode* child;
            if(root->children[index]!=NULL){//ye character present hh
                child=root->children[index];
            }
            else{//absent
                return false;
            }
            return searchUtil(child,word.substr(1));
        }
        bool searchWord(string word){
            return searchUtil(root,word);
        }
        void delUtil(trieNode* root,string word){
            if(word.length()==0){
                root->isTerminal=false;
                return;
            }
            int index=word[0] - 'A';
            trieNode* child;
            if(root->children[index]!=NULL){
                child=root->children[index];
            }
            else{//absent
                return ;
            }
            return delUtil(child,word.substr(1));
        }
        void del(string word){
            return delUtil(root,word);
        }
};
int main(){
    trie* t=new trie();
    t->insertWord("ABCD");
    cout<<"Present or not "<<t->searchWord("ABCD");//1
    t->del("ABCD");
    cout<<endl<<"Present or not "<<t->searchWord("ABCD");//0
    return 0;
}
/*
The root node of the trie always represents the null node.
Each child of nodes is sorted alphabetically.
Each node can have a maximum of 26 children (A to Z).
Each node (except the root) can store one letter of the alphabet.
*/