int dfs(BinaryTreeNode<int>* root){
        if(root==NULL) return 0;
        int lh=dfs(root->left);
        if(lh==-1) return -1;
        int rh=dfs(root->right);
        if(rh==-1) return -1;
        
        if(abs(lh - rh)>1) return -1;
        return 1+max(lh, rh);
    }
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    return dfs(root)!=-1;
}