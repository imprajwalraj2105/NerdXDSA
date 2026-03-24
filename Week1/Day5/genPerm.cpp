// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void generatePerm(vector<int>&nums, int idx){
    if(idx==nums.size()){
        cout<<"[";
        for(int i=0;i<nums.size();i++){
            cout<<nums[i];
            if(i!=nums.size()-1)cout<<", ";
        }
        cout<<"]"<<endl;
    }
    for(int i=idx;i<nums.size();i++){
        swap(nums[i],nums[idx]);
        generatePerm(nums,idx+1);
        swap(nums[i],nums[idx]);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    generatePerm(nums,0);
    return 0;
}