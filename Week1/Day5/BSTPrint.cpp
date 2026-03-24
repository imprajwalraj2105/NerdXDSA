// You are using GCC
#include<bits/stdc++.h>
using namespace std;

struct Node {
    int val;
    Node* left;
    Node* right;
    Node(int x) {
        val = x;
        left = right = NULL;
    }
};

Node* build(vector<int>& arr, int l, int r) {
    if(l > r) return NULL;

    int mid = (l + r) / 2;
    Node* root = new Node(arr[mid]);

    root->left = build(arr, l, mid - 1);
    root->right = build(arr, mid + 1, r);

    return root;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++) cin >> arr[i];

    Node* root = build(arr, 0, n - 1);

    cout << root->val << " -> (left: ";

    if(root->left) cout << root->left->val;
    else cout << "null";

    cout << ", right: ";

    if(root->right) cout << root->right->val;
    else cout << "null";

    cout << ")";

    return 0;
}