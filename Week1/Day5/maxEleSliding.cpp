// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void findMax(int start,int end, vector<int>&nums,vector<int>&max){
    int maxi = nums[start];
    for(int i=start;i<=end;i++){
        if(nums[i]>maxi){
            maxi = nums[i];
        }
    }
    max.push_back(maxi);
}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int k;
    cin>>k;
    vector<int>max;
    for(int i=0;i+k<=n;i++){
        findMax(i,i+k-1,nums,max);
    }
    cout<<"Maximum values in each sliding window: ";
    for(int x:max)cout<<x<<" ";
    return 0;
}