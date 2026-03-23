// You are using GCC
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>heights(n);
    for(int i=0;i<n;i++)cin>>heights[i];
    stack<int>st;
    int maxArea = 0;
    for(int i=0;i<=n;i++){
        int currHeight =(i==n)?0:heights[i];
        while(!st.empty()&& currHeight<heights[st.top()]){
            int h = heights[st.top()]; st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            maxArea = max(maxArea, h * w);
        }
        st.push(i);
    }
    cout<<"Max Area: "<<maxArea;
    return 0;
}