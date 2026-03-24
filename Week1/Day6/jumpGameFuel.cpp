#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> fuel(n);
    for(int i = 0; i < n; i++) cin >> fuel[i];

    int maxReach = 0;

    for(int i = 0; i < n; i++){
        if(i > maxReach){
            cout << "No";
            return 0;
        }
        maxReach = max(maxReach, i + fuel[i]);
    }

    cout << "Yes";
    return 0;
}