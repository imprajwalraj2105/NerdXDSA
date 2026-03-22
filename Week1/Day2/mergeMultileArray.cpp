// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>res;
    while(n){
        int size;
        cin>>size;
        for(int i=0;i<size;i++){
            int num;
            cin>>num;
            res.push_back(num);
        }
        n--;
    }
    sort(res.begin(),res.end());
    for(int x:res)cout<<x<<" ";
    return 0;
}