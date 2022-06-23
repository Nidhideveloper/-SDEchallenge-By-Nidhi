#include<bits/stdc++.h>
vector<int> verticalOrderTraversal(TreeNode<int> *root)
{
    //    Write your code here.
    vector<int> ans;
    map<int, map<int, vector<int>>> nodes;
    queue<pair<TreeNode<int>*, pair<int, int>>> q;
    if(root==NULL) return ans;
    q.push({root, {0, 0}});
    while(!q.empty()){
        auto tmp = q.front();
        q.pop();
        TreeNode<int> * node=tmp.first;
        int hd=tmp.second.first;
        int level = tmp.second.second;
        nodes[hd][level].push_back(node->data);
        if(node->left) q.push({node->left, {hd-1, level+1}});
        if(node->right) q.push({node->right, {hd+1, level+1}});
    }
    for(auto x:nodes){
        for(auto y:x.second){
            for(auto k:y.second){
                ans.push_back(k);
            }
        }
    }
    return ans;
}