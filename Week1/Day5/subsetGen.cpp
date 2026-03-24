// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void generateSubsets(int idx,vector<int>&nums,vector<int>& current){
    cout<<"[";
    for(int i=0;i<current.size();i++){
        cout<<current[i];
        if (i != current.size() - 1) cout << ", ";
    }
    cout<<"]"<<endl;
    for(int i=idx;i<nums.size();i++){
        current.push_back(nums[i]);
        generateSubsets(i+1,nums,current);
        current.pop_back();
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    vector<int>current;
    cout<<"All possible subsets:"<<endl;
    generateSubsets(0,nums,current);
    return 0;
}