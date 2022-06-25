/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
bool dfs(BinaryTreeNode<int> *root, int mn, int mx){
    if(root==NULL) return true;
    if(root->data>=mn && root->data<=mx)
    return dfs(root->left, mn, root->data) && dfs(root->right, root->data, mx);
    else return false;
}
bool validateBST(BinaryTreeNode<int> *root) {
    // Write your code here
    return dfs(root, INT_MIN, INT_MAX);
}