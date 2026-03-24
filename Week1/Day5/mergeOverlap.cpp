// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int,int>>intervals(n);
    for(int i=0;i<n;i++){
        cin>>intervals[i].first>>intervals[i].second;
    }
    sort(intervals.begin(),intervals.end());
    vector<pair<int,int>>merged;
    for(int i=0;i<n;i++){
        if(merged.empty()||merged.back().second<intervals[i].first){
            merged.push_back(intervals[i]);
        }else{
            merged.back().second = max(merged.back().second,intervals[i].second);
        }
    }
    for (auto &it : merged) {
        cout << "[" << it.first << ", " << it.second << "]\n";
    }
    return 0;
}