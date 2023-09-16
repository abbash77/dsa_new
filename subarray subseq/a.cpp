#include<iostream>
#include<vector>
using namespace std;



void printSubArrays(vector<int> arr, int start, int end)
{
    if (end == arr.size())
        return;
    else if (start > end)
        printSubArrays(arr, 0, end + 1);
    else {
        cout << "[";
        for (int i = start; i < end; i++)
            cout << arr[i] << ", ";
        cout << arr[end] << "]" << endl;
        printSubArrays(arr, start + 1, end);
    }
    return;
}


void printSubsequences(vector<int> arr, int index,
                       vector<int> &subarr,int n){
    if (index == n)
    {
        for (auto it:subarr){
            cout << it << " ";
        }
        if(subarr.size()==0)
            cout<<"{}";
        cout<<endl;
        return;
    }
    else{
        subarr.push_back(arr[index]);
        printSubsequences(arr, index + 1, subarr,n);
        subarr.pop_back();
        printSubsequences(arr, index + 1, subarr,n);
    }
    
}
int main()
{
    vector<int> arr = { 1, 2, 3 };
    // printSubArrays(arr, 0, 0);
    vector<int> d;
    printSubsequences(arr,0,d,3);
    return 0;
}