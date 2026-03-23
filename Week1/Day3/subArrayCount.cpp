// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++)cin>>nums[i];
    int target,cnt = 0;
    cin>>target;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=i;j<n;j++){
            sum+=nums[j];
            if(sum==target)cnt++;
        }
    }
    cout<<"Count: "<<cnt;
    return 0;
}