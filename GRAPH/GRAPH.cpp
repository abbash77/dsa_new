#include<iostream>
using namespace std;
#include<unordered_map>
#include<list>
template <typename T>
class Graph{
    public:
        unordered_map<T,list<T>> adj;
        void addEdge(T u,T v,bool dir){
            //dir=0 undirected graph;
            //dir=1 directed graph
            //create an edge from u to v
            adj[u].push_back(v);
            if(dir){
                adj[v].push_back(u);
            }
        } 
        void print(){
            for(auto i:adj){
                cout<<i.first<<"->";
                for(auto j:i.second){
                    cout<<j<<",";
                }
                cout<<endl;
            }
        }


};

int main(){
    int n;
    cout<<"enter the number of nodes"<<endl;
    cin>>n;
    int m;
    cout<<"enter the number of edges"<<endl;
    cin>>m;
    Graph<int> g;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //undirected graph
        g.addEdge(u,v,0);
    }
    g.print();


}