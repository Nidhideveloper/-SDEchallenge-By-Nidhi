
int height(TreeNode<int> * root, int &ans)
{
    if(!root) return 0;
    
    int lHeight = height(root->left, ans);
    int rHeight = height(root->right, ans);
    
    ans= max(ans, lHeight + rHeight);
    return 1+ max( lHeight , rHeight);

}
int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    if(!root) return 0;
    int ans=0;
    height(root, ans);
    return ans;
}
