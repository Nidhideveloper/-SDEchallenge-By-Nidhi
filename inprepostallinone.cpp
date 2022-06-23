void dfs(BinaryTreeNode<int> *root, vector<int> &pre, vector<int> &in, vector<int> &post){
    if(root==NULL) return;
    pre.push_back(root->data);
    dfs(root->left, pre, in, post);
    in.push_back(root->data);
    dfs(root->right, pre, in, post);
    post.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<int> pre, in, post;
    dfs(root, pre, in, post);
    return {in, pre, post};
}