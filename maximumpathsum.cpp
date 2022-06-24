long long int dfs(TreeNode<int> *root, long long int &ans){
    if(root==NULL) return 0;
    long long int l = dfs(root->left, ans);
    long long int r=dfs(root->right, ans);
    ans=max(ans, l+r+root->val);
    return max(l, r)+root->val;
}
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL) return -1;
    if(root->left==NULL || root->right==NULL) return -1;
    long long int ans=0;
    dfs(root, ans);
    return ans;
}