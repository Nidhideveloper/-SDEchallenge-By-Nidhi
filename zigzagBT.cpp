vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!
    vector<vector<int>> res;
    vector<int> ans;
        if(root==NULL) return ans;
        queue<BinaryTreeNode<int> *> q;
        q.push(root);
        bool flag=true;
        while(!q.empty()){
            int sz=q.size();
            vector<int> row(sz);
            for(int i=0; i<sz; i++){
                BinaryTreeNode<int> * node=q.front();
                q.pop();
                int indx=(flag)? i : (sz-1-i);
                row[indx]=node->data;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                
            }
            flag=!flag;
            res.push_back(row);
        }
    
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            ans.push_back(res[i][j]);
        }
    }
        return ans;
}
