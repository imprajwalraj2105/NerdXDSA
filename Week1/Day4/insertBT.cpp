// You are using GCC
#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
Node* buildBST(Node*root, int val){
    if(!root)return new Node(val);
    if(root->data>val){
        root->left = buildBST(root->left, val);
    }else{
        root->right = buildBST(root->right,val);
    }
    return root;
}
void levelOrder(Node* root){
    if(!root) return;
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
    cin>>n;
    Node*root = nullptr;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        root = buildBST(root,num);
    }
    int ele;
    cin>>ele;
    root = buildBST(root,ele);
    levelOrder(root);
    return 0;
}