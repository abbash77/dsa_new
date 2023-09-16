#include<iostream>
#include<set>
#include<unordered_set>

using namespace std;

int main(){
    set<string> s;
    s.insert("abc");
    s.insert("zjak");
    s.insert("bcd");//time complexity is logn
    //sorted order me insert hoga and duplicate nhi honge isme
    auto itr=s.find("abc");//itr return krega exist nhi kara to .end() ka iterator aa jayega
    //printing
    //1
    for(auto itr=s.begin();itr!=s.end();itr++){
        cout<<(*itr)<<endl;
    }
    //2
    //    OR
    for(string value :s){
        cout<<value<<endl;
    }
    // ******************************************
    s.erase(itr);//or s.erase("abc")
// ---------------------------------------------------------------------
    //ques 1 on sets
    /*
    given n strings print unique strings in lexiographical order 
    n<=10 to the power 5
    s<=100000
    */
   set<string> s;
   int n;
   cin>>n;
   for(int i=0;i<n;i++){
       string str;
       cin>>str;
       s.insert(str);
   }
   for(auto value :s){
       cout<<value <<endl;
   }
//    -------------------------------------------------------------------
    // unordered set
    unordered_set<string > s;
    s.insert("abc");
    s.insert("zhsh");
    s.insert("audn");
    /*
    abc
    zhsh
    audn
    *///not sorted complexity is O(1)
    // ----------------------------------------------------------------------------------
    // multiset
    //allows multiple value to insert in set
    multiset<string> s;
    s.insert("abc");
    s.insert("zhsh");
    s.insert("abc");
    /*
    abc
    abc
    zhsh//time complexity is logn
    */
   auto it=s.find("abc"); //first occurrence ka iterator return krega
   //if we to del abc
   if(it!=s.end()){
       s.erase(it);//first occurence ko del krega bas
   }
//    -------------------------------------------------------------------
//    now agar saare abc del krne hh hme to
    s.erase("abc");//abc ke saare occurence ko del krdo agar value pass krenge to 
    // mutiset me saare operation logn hote h

    return 0;
}