// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int target;
    cin>>target;
    for(int i=0;i<n;i++){
        if(nums[i]==target){
            cout<<i;
            return 0;
        }
    }
    cout<<"-1";
    return 0;
}