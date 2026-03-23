#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, p;
    cin >> n >> p;

    vector<vector<int>> adj(n);
    vector<int> indegree(n, 0);

    for(int i = 0; i < p; i++){
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);  // b must be done before a
        indegree[a]++;
    }

    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; i++)
        if(indegree[i] == 0) pq.push(i);

    int count = 0;
    while(!pq.empty()){
        int node = pq.top(); pq.pop();
        count++;
        for(int neigh : adj[node]){
            indegree[neigh]--;
            if(indegree[neigh] == 0) pq.push(neigh);
        }
    }

    cout << (count == n ? "Possible" : "Not Possible");
    return 0;
}