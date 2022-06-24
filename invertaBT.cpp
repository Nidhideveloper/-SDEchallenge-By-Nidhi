#include<bits/stdc++.h>
void help(TreeNode<int> *root, TreeNode<int> *leaf, stack<pair<TreeNode<int>*, bool>> &st, bool prev){
    if(!st.empty() && st.top().first==leaf) return;
    if(root==NULL) return;
    st.push({root, prev});
    help(root->left, leaf, st, true);
    help(root->right, leaf, st, false);
    if(!st.empty() && st.top().first->data!=leaf->data) st.pop();
}
TreeNode<int> * invertBinaryTree(TreeNode<int> *root, TreeNode<int> *leaf)
{
	// Write your code here.
    stack<pair<TreeNode<int>*,bool>> s;
    help(root, leaf, s, false);
    bool prev=s.top().second;
    s.pop();
    TreeNode<int> *tmp=leaf;
    while(!s.empty()){
        if(prev==true){
            s.top().first->left=NULL;
            tmp->left=s.top().first;
        }
        else{
            s.top().first->right=s.top().first->left;
            s.top().first->left=NULL;
            tmp->left=s.top().first;
        }
        tmp=s.top().first;
        prev=s.top().second;
        s.pop();
    }
    if(leaf->right){
        leaf->left=leaf->right;
        leaf->right=NULL;
    }
    return leaf;
}
