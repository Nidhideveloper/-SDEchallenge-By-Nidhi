void solve(BinaryTreeNode < int > *root, int &mx){
    if(root==NULL) return;
    solve(root->left, mx);
    solve(root->right, mx);
    if(root->left || root->right) root->data=0;
    if(root->left==NULL && root->right==NULL) root->data=mx;
    if(root->right) root->data+=root->right->data;
    if(root->left) root->data+=root->left->data;
    return;
}

void find(BinaryTreeNode < int >* root, int &mx){
    if(root==NULL) return;
    find(root->left, mx);
    mx=max(mx, root->data);
    find(root->right,mx);
    return;
}
void changeTree(BinaryTreeNode < int > * root) {
    // Write your code here.
    int mx=0;
    find(root, mx);
    solve(root, mx);
    return;
}  