************************************************************/
#include <bits/stdc++.h>
vector<int> getTopView(TreeNode<int> *root) {
    // Write your code here.
     vector<int> ans;
    if(root==NULL)
        return ans;
        map<int, int> m;
        queue<pair<TreeNode<int>*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto tmp = q.front();
            q.pop();
            TreeNode<int>* node = tmp.first;
            int hd=tmp.second;
            if(m.find(hd)==m.end()){
                m[hd]=node->val;
            }
            if(node->left) q.push({node->left, hd-1});
            if(node->right) q.push({node->right, hd+1});
        }
        for(auto it:m) ans.push_back(it.second);
        return ans;
}