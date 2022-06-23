vector<int> bottomView(BinaryTreeNode<int> * root){

    // Write your code here.
     map<int, int> m;
        queue<pair<BinaryTreeNode<int> *, int>> q;
        vector<int> ans;
        if(root==NULL) return ans;
        q.push({root, 0});
        while(!q.empty()){
            auto temp = q.front();
            BinaryTreeNode<int> * node = temp.first;
            int hd=temp.second;
            q.pop();
            m[hd]=node->data;
            if(node->left) q.push({node->left, hd-1});
            if(node->right) q.push({node->right, hd+1});
        }
        for(auto it: m ) ans.push_back(it.second);
        return ans;
    
}
