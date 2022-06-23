#include <bits/stdc++.h>
int getMaxWidth(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL) return 0;
    queue<TreeNode<int> *> q;
    q.push(root);
    int cnt=0;
    while(!q.empty()){
        int sz=q.size();
        cnt=max(cnt, sz);
        for(int i=0; i<sz; i++){
            TreeNode<int> *node = q.front();
            q.pop();
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
    }
    return cnt;
}