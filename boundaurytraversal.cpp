void leftvw(TreeNode<int> *root, vector<int> &ans){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
    ans.push_back(root->data);
    leftvw(root->left, ans);
    if(root->left==NULL){
        leftvw(root->right, ans);
        return;
    }
    return;
}

void rightvw(TreeNode<int> *root, vector<int> &ans){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL) return;
    rightvw(root->right, ans);
    if(root->right==NULL){
        rightvw(root->left, ans);
    }
    ans.push_back(root->data);
    return;
}

void leaf(TreeNode<int> *root, vector<int> &ans){
    if(root==NULL) return;
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }
    leaf(root->left, ans);
    leaf(root->right, ans);
    return;
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(root==NULL) return ans;
    ans.push_back(root->data);
    if(root->left) leftvw(root->left,ans);
    leaf(root->left,ans);
    leaf(root->right, ans);
    if(root->right) rightvw(root->right, ans);
    return ans;
}