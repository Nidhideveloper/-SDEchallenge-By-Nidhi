int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	//    Write your code here
    if(root==NULL) return -1;
    if(root->data==x || root->data==y) return root->data;
    int lf=lowestCommonAncestor(root->left, x, y);
    int rt = lowestCommonAncestor(root->right, x, y);
    if(lf==-1) return rt;
    else if(rt==-1) return lf;
    else return root->data;
}