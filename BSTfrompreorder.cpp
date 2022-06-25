/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
#include <bits/stdc++.h>
 TreeNode<int>* helper(vector<int>& arr,int l,int r){
        //BASE CASE
        if(l>r)
            return NULL;
        
        //First element is root itself
        TreeNode<int> *root=new TreeNode<int>(arr[l]);
        
        int pos=l;     //For corner case that only 1 element is given it the array
        for(int i=l+1; i<=r; i++){   //Find the index of last element which is smaller than the root node
            if(arr[i]<root->data)
                pos=i;
            else
                break;
        }
        root->left=helper(arr,l+1,pos);  //Make left subtree
        root->right=helper(arr,pos+1,r); //Make right subtree
        return root;
    }
TreeNode<int>* preOrderTree(vector<int> &preorder){
    // Write your code here.
        int l=0;                  //Left most element of array
        int r=preorder.size()-1;  //Right most element of the array
        return helper(preorder,l,r);
}