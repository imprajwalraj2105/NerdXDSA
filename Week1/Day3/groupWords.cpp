// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string>words(n);
    for(int i=0;i<n;i++)cin>>words[i];
    unordered_map<string,vector<string>>mp;
    for(auto& word:words){
        string key = word;
        sort(key.begin(),key.end());
        mp[key].push_back(word);
    }
    vector<vector<string>>groups;
    for(auto&p : mp){
        vector<string>group = p.second;
        sort(group.begin(),group.end());
        groups.push_back(group);
    }
    sort(groups.begin(), groups.end(), [](vector<string>& a, vector<string>& b){
    if(a.size() != b.size())
        return a.size() < b.size();
    return a[0] < b[0];
});
    cout<<"Groups: "<<groups.size()<<endl;
    for(auto& group:groups){
        for(int i=0;i<group.size();i++){
            cout<<group[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}