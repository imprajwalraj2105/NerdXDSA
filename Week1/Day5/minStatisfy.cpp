// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n1,n2;
    cin>>n1;
    vector<int>child(n1);
    for(int i=0;i<n1;i++)cin>>child[i];
    cin>>n2;
    vector<int>avail(n2);
    for(int i=0;i<n2;i++)cin>>avail[i];
    int cnt=0;
    sort(child.begin(),child.end());
    sort(avail.begin(),avail.end());
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(child[i]<=avail[j]){
            cnt++;
            i++;
        }
        j++;
    }
    cout<<cnt;
    return 0;
}