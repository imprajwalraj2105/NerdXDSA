// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>coins(n);
    for(int i=0;i<n;i++)cin>>coins[i];
    int amount;
    cin>>amount;
    vector<int>dp(amount+1,INT_MAX);
    dp[0]=0;
    for(int i = 1; i <= amount; i++){
        for(int coin : coins){
            if(i >= coin && dp[i - coin] != INT_MAX){
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }

    if(dp[amount] == INT_MAX) cout << -1;
    else cout << dp[amount];

    return 0;
}