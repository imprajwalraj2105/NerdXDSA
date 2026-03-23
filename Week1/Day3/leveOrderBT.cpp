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
Node* buildBT(vector<int>&vals){
    if(vals.empty())return nullptr;
    Node* root = new Node(vals[0]);
    queue<Node*>q;
    q.push(root);
    int i = 1;
    while(!q.empty()&&i<vals.size()){
        Node* curr = q.front();q.pop();
        if(i<vals.size()&& vals[i]!=-1){
            curr->left = new Node(vals[i]);
            q.push(curr->left);
        }
        i++;
        if(i<vals.size() && vals[i]!=-1){
            curr->right = new Node(vals[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}
void levelOrder(Node* root){
    if(!root)return;
    queue<Node*>q;
    q.push(root);
    int level = 0 ;
    while(!q.empty()){
        int size  = q.size();
        cout<<"Level "<<level<<": ";
        for(int i=0;i<size;i++){
            Node* curr = q.front();q.pop();
            cout<<curr->data;
            if(i<size-1)cout<<" ";
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
        level++;
        cout<<endl;
    }
}
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<int>vals(n);
    for(int i=0;i<n;i++)cin>>vals[i];
    Node* root = buildBT(vals);
    levelOrder(root);
    return 0;
}