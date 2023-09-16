#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    //creation
    unordered_map<string,int> m;
    //insertion
    pair<string,int> p=make_pair("babbar",3);
    m.insert(p);
    pair<string,int> p2("love",2);
    m.insert(p2);

    m["mera"]=1;
    m["mera"]=2;//overwrite kr dega 
    //key unique hongi

    //search
    cout<<m["mera"]<<endl;//2
    cout<<m.at("babbar")<<endl;//3
    cout<<m.at("unknownkey")<<endl;//error
    cout<<m["unknownKey"]<<endl;//0 aayega ek entry bna dega unknown key ke corresponding
    cout<<m.at("unknownkey")<<endl;//ab error nbi aayega kyuki line 23 me entry ban chuki hh 0 aayega


    //size
    cout<<m.size()<<endl;

    //to check presence
    cout<<m.count("bro")<<endl;//if no key name bro to 0 dega warna value dega

    //erase
    m.erase("love");

    //traverse
    for(auto i:m){
        cout<<i.first<<" "<<i.second<<endl;
    }
    //traverse using iterator
    unordered_map<string,int> :: iterator it=m.begin();
    while(it!=m.end()){
        cout<<it->first<<" "<<it->second<<endl;
    }

    return 0;
}