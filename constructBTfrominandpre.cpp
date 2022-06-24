#include <bits/stdc++.h>
TreeNode<int> * build(vector<int> &pre, int ps, int pe, vector<int> &in, int ins, int ine, map<int, int> &inmap){
        if(ps>pe || ins>ine) return NULL;
        TreeNode<int> * root = new TreeNode<int> (pre[ps]);
        int inRoot = inmap[root->data];
        int numleft=inRoot - ins;
        root->left = build(pre, ps+1, ps+numleft, in, ins, inRoot-1, inmap);
        root->right = build(pre, ps+numleft+1, pe, in, inRoot+1, ine, inmap );
        return root;
    }
TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
     map<int, int> inMap;
        for(int i=0; i<inorder.size(); i++) inMap[inorder[i]]=i;
        TreeNode<int> * root=build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
}