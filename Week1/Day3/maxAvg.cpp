#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++) cin >> nums[i];
    int k;
    cin >> k;

    // First window sum
    int sum = 0;
    for(int i = 0; i < k; i++) sum += nums[i];  // ✅

    int maxSum = sum;  // ✅ initialize with first window
    int startIdx = 0;

    // Slide window
    for(int i = k; i < n; i++){
        sum += nums[i] - nums[i-k];
        if(sum > maxSum){
            maxSum = sum;
            startIdx = i - k + 1;
        }
    }

    double avg = (double)maxSum / k;
    if(avg == (int)avg)
        cout << "Max Average: " << (int)avg << "\n";
    else
        cout << "Max Average: " << avg << "\n";

    cout << "Subarray indices: " << startIdx << " " << startIdx + k - 1;
    return 0;
}