#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;


bool comparator(pair<int,int> i1,pair<int,int> i2){
    return i1.first<i2.first;// whether “first” argument should be placed before the
    // passed “second” argument or not.//if true then no swapping 
}


int main(){
    vector<pair<int,int>> v{{1,2},{3,4},{2,7},{9,6},{4,9}};
    sort(v.begin(),v.end(),comparator);
    for(int i=0;i<v.size();i++){
        cout<<v[i].first<<" "<<v[i].second<<endl;
    }
    return 0;
}