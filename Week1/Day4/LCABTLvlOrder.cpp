TreeNode* buildTree(vector<string>& nodes, int idx){
    if(idx >= nodes.size() || nodes[idx] == "null" || nodes[idx] == "-1")
        return nullptr;
    TreeNode* root = new TreeNode(stoi(nodes[idx]));
    root->left  = buildTree(nodes, 2*idx + 1);  // left child
    root->right = buildTree(nodes, 2*idx + 2);  // right child
    return root;
}

// LCA for BST
TreeNode* lca(TreeNode* root, int p, int q){
    if(!root) return nullptr;
    if(root->val > p && root->val > q)
        return lca(root->left, p, q);   
    if(root->val < p && root->val < q)
        return lca(root->right, p, q);  
    return root;                    
}
