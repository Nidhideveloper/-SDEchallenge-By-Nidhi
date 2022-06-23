void dfs(TreeNode* root, vector<int> &pre){
    if(root==NULL) return;
    pre.push_back(root->data);
    dfs(root->left, pre);
    dfs(root->right, pre);
}
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> preorder;
    dfs(root, preorder);
    return preorder;
}