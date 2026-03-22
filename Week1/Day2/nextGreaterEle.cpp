// You are using GCC
// You are using GCC
#include<bits/stdc++.h>
using namespace std;
vector<int> findGreater(vector<int>nums1, vector<int>& nums2){
    unordered_map<int,int>nge;
    stack<int>st;
    for(int i=nums1.size();i>=0;i--){
        while(!st.empty()&&st.top()<=nums1[i])st.pop();
        if(st.empty())nge[nums1[i]]=-1;
        else nge[nums1[i]]=st.top();
        st.push(nums1[i]);
    }
    vector<int>res;
    for(int num:nums2)res.push_back(nge[num]);
    return res;
}
int main(){
    int n1,n2;
    cin>>n1;
    vector<int>nums1(n1);
    for(int i=0;i<n1;i++)cin>>nums1[i];
    cin>>n2;
    vector<int>nums2(n2);
    for(int i=0;i<n2;i++)cin>>nums2[i];
    vector<int>ans;
    ans = findGreater(nums1,nums2);
    for(int x:ans)cout<<x<<" ";
    return 0;
}