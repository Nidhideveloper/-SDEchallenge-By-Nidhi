vector<int> getLeftView(TreeNode<int> *root)
{
    //    Write your code here
    vector<int> ans;
   if(root==NULL) return ans;
   queue<TreeNode<int>*> q;
   q.push(root);
   while(!q.empty()){
       int sz=q.size();
       for(int i=0; i<sz; i++){
           TreeNode<int>* node = q.front();
           q.pop();
           if(node->left) q.push(node->left);
           if(node->right) q.push(node->right);
           if(i==0) ans.push_back(node->data);
       }
   }
   return ans;
}