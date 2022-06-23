void dfs(vector<int> &in, TreeNode* root){
    if(root==NULL) return;
    dfs(in, root->left);
    in.push_back(root->data);
    dfs(in, root->right);
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> inorder;
    dfs(inorder, root);
    return inorder;
}