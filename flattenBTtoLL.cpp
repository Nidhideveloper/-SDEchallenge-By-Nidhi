#include<bits/stdc++.h>
TreeNode<int> *flattenBinaryTree(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL) return root;
    stack<TreeNode<int>*> st;
    st.push(root);
    TreeNode<int>* tmp=root;
    TreeNode<int>* node=tmp;
    while(!st.empty()){
        tmp=st.top();
        st.pop();
        if(tmp->right) st.push(tmp->right);
        if(tmp->left) st.push(tmp->left);
        if(!st.empty()) tmp->right=st.top();
        tmp->left=NULL;
    }
    return node;
}