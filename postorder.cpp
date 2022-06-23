
void dfs(TreeNode* root, vector<int> &post){
    if(root==NULL) return;
    dfs(root->left, post);
    dfs(root->right, post);
    post.push_back(root->data);
}
vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int> postorder;
    dfs(root, postorder);
    return postorder;
}