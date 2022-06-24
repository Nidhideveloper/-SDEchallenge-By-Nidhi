#include <bits/stdc++.h>
TreeNode<int> * build(vector<int> &in, int ins, int ine, vector<int> &post, int ps, int pe, map<int, int> &inmap){
        if(ps>pe || ins>ine) return NULL;
        TreeNode<int> * root = new TreeNode<int> (post[pe]);
        int inRoot = inmap[root->data];
        int numleft = inRoot - ins;
        root->left = build(in, ins, inRoot - 1, post, ps, ps+numleft-1, inmap);
        root->right = build(in, inRoot+1, ine, post, ps+numleft, pe-1, inmap);
        return root;
    }
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postorder, vector<int>& inorder) 
{
	// Write your code here.
    map<int, int> inMap;
        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]]=i;
        }
        TreeNode<int> * root = build(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inMap);
        return root;
}
