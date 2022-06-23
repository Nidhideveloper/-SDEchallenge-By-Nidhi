void dfs(TreeNode<int> *root, int x, vector<int> &path){
    if(root==NULL) return;
    path.push_back(root->data);
    if(root->data==x) return;
    dfs(root->left, x, path);
    dfs(root->right, x, path);
    if(path[path.size()-1]!=x) path.pop_back();
}

vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
    vector<int> path;
    dfs(root, x, path);
    return path;
    
}
