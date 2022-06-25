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
void dfs(BinaryTreeNode<int>* root, BinaryTreeNode<int>* &next, BinaryTreeNode<int>* &prev){
    if(root==NULL) return;
    dfs(root->left, next, prev);
    if(prev==NULL) next=root;
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    dfs(root->right, next, prev);
    
}
BinaryTreeNode<int>* BTtoDLL(BinaryTreeNode<int>* root) {
    // Write your code here
    BinaryTreeNode<int> *next=NULL, *prev=NULL;
    dfs(root, next, prev);
    return next;
}