#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    queue<int> q;
    while(n--){
        int num;
        cin >> num;
        if(num == 1){
            int val;
            cin >> val;
            q.push(val);
            cout << val << " added" << endl;
        }
        else if(num == 2){
            if(q.empty()){ cout << "Queue is empty" << endl; continue; }
            cout << q.front() << " removed" << endl;
            q.pop();
        }
        else if(num == 3){
            if(q.empty()){ cout << "Queue is empty" << endl; continue; }
            cout << q.front() << " at top" << endl;
        }
        else if(num == 4){
            cout << (q.empty() ? "True" : "False") << endl;
        }
    }
    return 0;
}