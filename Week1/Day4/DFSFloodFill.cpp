// You are using GCC
#include<bits/stdc++.h>
using namespace std;
void dfs(vector<vector<int>>& grid,int i, int j, int m, int n){
    if(i<0||i>=n ||j<0 || j>=m ||grid[i][j]==0) return;
    grid[i][j]=0;
    dfs(grid,i-1,j,m,n);
    dfs(grid,i+1,j,m,n);
    dfs(grid,i,j-1,m,n);
    dfs(grid,i,j+1,m,n);
}
int main(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>>grid(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    int cont = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j]==1){
                cont++;
                dfs(grid,i,j,m,n);
            }
        }
    }
    cout<<cont;
    return 0;
}