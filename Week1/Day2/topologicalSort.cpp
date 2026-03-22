#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    
    vector<vector<int>>adj(n);
    vector<int>indegree(n,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        indegree[v]++;
    }
    queue<int>q;
    vector<int>res;
    for(int i=0;i<n;i++){
        if(indegree[i]==0)q.push(i);
    }
    while(!q.empty()){
        int node = q.front();q.pop();
        res.push_back(node);
        for(int neigh: adj[node]){
            indegree[neigh]--;
            if(indegree[neigh]==0)q.push(neigh);
        }
    }
    sort(res.begin(),res.end());
    if(res.size()!=n){
        cout<<-1;
        return 0;
    }
    for(int x:res)cout<<x<<" ";
    return 0;
}
