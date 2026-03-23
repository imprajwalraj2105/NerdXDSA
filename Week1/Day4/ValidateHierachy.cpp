// You are using GCC
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int v) : val(v), left(nullptr), right(nullptr){}
};

Node* buildTree(vector<int>& vals){
    if(vals.empty() || vals[0] == -1) return nullptr;
    Node* root = new Node(vals[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;
    while(!q.empty() && i < vals.size()){
        Node* curr = q.front(); q.pop();
        if(i < vals.size() && vals[i] != -1){
            curr->left = new Node(vals[i]);
            q.push(curr->left);
        }
        i++;
        if(i < vals.size() && vals[i] != -1){
            curr->right = new Node(vals[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

bool validate(Node* root, long min, long max){
    if(!root) return true;
    if(root->val <= min || root->val >= max) return false;
    return validate(root->left, min, root->val) &&
           validate(root->right, root->val, max);
}

int main(){
    int n;
    cin >> n;
    vector<int> vals(n);
    for(int i = 0; i < n; i++) cin >> vals[i];
    Node* root = buildTree(vals);
    cout << (validate(root, LONG_MIN, LONG_MAX) ? "Valid" : "Invalid");
    return 0;
}