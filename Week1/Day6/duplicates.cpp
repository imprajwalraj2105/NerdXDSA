// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)mp[nums[i]]++;
    for(auto& it:mp){
        if(it.second>1){
            cout<<"Duplicate Found";
            return 0;
        }
    }
    cout<<"No Duplicates";
    return 0;
}