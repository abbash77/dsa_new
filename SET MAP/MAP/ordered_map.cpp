#include<iostream>
#include<map>
using namespace std;


int main(){
    map<int,string> m;
    m[1]="abc";
    m[3]="cdc";
    m[2]="ans";
    m.insert({4,"agf"});
    //all the keys should be unique//

    // for ordered map sorted(key ko sort krenge) order me store krenge (it takes logn time for insertion)**
    //access time complexity is also logn
    /*
    1 abc
    2 ans
    3 cdc 
    4 agf
    */

   //1 method of printing

//    m.size() return current size

    map<int, string> ::iterator itr;
    //and itr points to a pair like (1 ,abc) 
    for(itr=m.begin();itr!=m.end();itr++){//*******m.end() mtlb last ka bagal waala jagah jispe koi value nhi hh********
        cout<<(*itr).first<<" "<<(*itr).second<<endl;
    }
    //2nd method of printing
    for(auto &pr:m){
        cout<<pr.first<<" "<<pr.second<<endl;
    }
    // -----------------------------------------------------------------------
    auto it= m.find(3);// m.find returns an iterator agar key mil jayegi to uska iterator de dega aur agar nhi mili 
    //to end ka iterator de dega*******
    if(it==m.end()){
        cout<<"Not present ";
    }
    else{
        cout<<"present:"<<(*it).first<<" "<<(*it).second<<endl;//3 cdc
    }//.find ki complexity is also logn

    //------------------------------------------------------------------------------------------
    m.erase(3);//3 cdc delete ho jayega ...isme iterator bhi de skte m.erase(itr) itr jisko point krega usko ye del 
    //kr dega
    //m.erase me aisa iterator mat do jispe value hi na ho jaise m.end( ) mat do warna error dega
    // if(it!=m.end()){
    //     m.erase(it);
    // } ye kro sahi rahega error nhi aayega ab .erase ki wajah se
    // ---------------------------------------------------------------------------------------
    m.clear();//clears the map
    // ------------------------------------------------------------------------------------------
    map<string,string> map1;
    //important point 
    //insertion also dependent on key sometimes mp if key is a string
    map1["abdc"]="jkajk";//iski complexity s.size()*logn //where s is string(key) that we are inserting
    //kyuki keys me aapas me comparison kon upar rhe kon niche and n is no of element in map before inserting
    // ______________________________________________________________________________________________
    // 1st ques on map
    //given N strings print unique strings in lexiographical order with their frequency
    //N<=10 to the power 5
    // |s|<=100

    // input 8 abc def abc ghj jkl ghj ghj abc
    // ***********************************
    // soln
    /**/
    map<string,int> map2;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){//agar string badi hogi to prob ho jayegi as complexity is s.size()*logn
        string s;
        cin>>s;
        map2[s]=map2[s]+1;//or map[s]++;
    }
    for(auto pr:m){
        cout<<pr.first<<" "<<pr.second<<endl;
    }


    return 0;
}