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

int diameter = 0;

int height(Node* root){
    if(!root) return 0;
    int left  = height(root->left);
    int right = height(root->right);
    diameter = max(diameter, left + right);  // update diameter at each node
    return 1 + max(left, right);
}

int main(){
    int n;
    cin >> n;
    vector<int> vals(n);
    for(int i = 0; i < n; i++) cin >> vals[i];
    Node* root = buildTree(vals);
    height(root);
    cout << diameter;
    return 0;
}