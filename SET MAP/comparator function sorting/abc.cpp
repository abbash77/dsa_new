#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;                    
bool compare(string a,string b){
    return a+b > b+a;
}
string largestNumber(vector<int>& nums) {
        vector<string> container;
        for(int i : nums)  container.push_back(to_string(i));
        for(int i=0;i<container.size();i++){
            cout<<container[i]<<" ";
        }
        cout<<endl;
        sort(container.begin(),container.end(),compare);
        for(int i=0;i<container.size();i++){
            cout<<container[i]<<" ";
        }
        string result;
        for(int i=0;i<container.size();i++)  result+=container[i];
        return result[0]=='0'? "0" : result;
    }

int main(){

    vector<int> arr={3,30,34,5,9};
    string a=largestNumber(arr);
    // cout<<a;


    return 0;
}