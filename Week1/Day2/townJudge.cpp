// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    vector<int>indegree(n+1,0);
    vector<int>outdegree(n+1,0);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        outdegree[a]++;
        indegree[b]++;
    }
    for(int i=1;i<=n;i++){
        if(indegree[i]==n-1 && outdegree[i]==0){
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}