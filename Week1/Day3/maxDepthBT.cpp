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
Node* insert(vector<int>&vals){
    if(vals.size()<=0)return nullptr;
    Node* root = new Node(vals[0]);
    queue<Node*>q;
    q.push(root);
    int i=1;
    while(!q.empty()&&i<vals.size()){
        Node* curr = q.front();q.pop();
        if(i<vals.size()&&vals[i]!=-1){
            curr->left = new Node(vals[i]);
            q.push(curr->left);
        }
        i++;
        if(i<vals.size()&&vals[i]!=-1){
            curr->right = new Node(vals[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
int maxDepth(Node* root){
    if(!root)return 0;
    return 1+max(maxDepth(root->left),maxDepth(root->right));
}
int main(){
    int n;
    cin>>n;
    vector<int>vals(n);
    for(int i=0;i<n;i++)cin>>vals[i];
    Node* root = insert(vals);
    cout<<"Depth: "<<maxDepth(root);
    return 0;
}