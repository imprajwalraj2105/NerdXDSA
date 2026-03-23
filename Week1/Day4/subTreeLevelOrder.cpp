#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr){}
};

// Build tree from level-order input
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

// Find node by value
Node* findNode(int val, Node* root){
    if(!root) return nullptr;
    if(root->data == val) return root;
    Node* left = findNode(val, root->left);
    if(left) return left;
    return findNode(val, root->right);
}

// Level order traversal
void levelOrder(Node* root){
    if(!root){ cout << "[]"; return; }
    queue<Node*> q;
    q.push(root);
    bool first = true;
    while(!q.empty()){
        Node* curr = q.front(); q.pop();
        if(!first) cout << " ";
        cout << curr->data;
        first = false;
        if(curr->left) q.push(curr->left);
        if(curr->right) q.push(curr->right);
    }
}

int main(){
    int n;
    cin >> n;
    vector<int> vals(n);
    for(int i = 0; i < n; i++) cin >> vals[i];
    int target;
    cin >> target;

    Node* root = buildTree(vals);  // ✅ level-order build, not BST insert
    Node* start = findNode(target, root);

    if(start) levelOrder(start);
    else cout << "[]";

    return 0;
}