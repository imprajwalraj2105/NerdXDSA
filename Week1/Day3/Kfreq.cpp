#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n;

    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];

    cin >> k;

    unordered_map<int,int> freq;
    for(int x : nums) freq[x]++;

    priority_queue<pair<int,int>> pq;
    for(auto &p : freq)
        pq.push({p.second, p.first}); // freq, value

    vector<int> result;
    for(int i = 0; i < k; i++) {
        result.push_back(pq.top().second);
        pq.pop();
    }

    sort(result.begin(), result.end());

    cout << "Top K Frequent: [";
    for(int i = 0; i < result.size(); i++) {
        cout << result[i];
        if(i < result.size()-1) cout << ", ";
    }
    cout << "]" << endl;
}