/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
#include<bits/stdc++.h>
class BSTiterator
{
    public:
    stack<TreeNode<int>*> s; 
    BSTiterator(TreeNode<int> *root)
    {
        // write your code here
        inorder(root);
    }
    void inorder(TreeNode<int>* root){
        while(root){
            s.push(root);
            root=root->left;
        }
    }

    int next()
    {
        // write your code here
        TreeNode<int>* cur=s.top();
        s.pop();
        inorder(cur->right);
        return cur->data;
    }

    bool hasNext()
    {
        // write your code here
        return !s.empty();
    }
};


/*
    Your BSTIterator object will be instantiated and called as such:
    BSTIterator iterator(root);
    while(iterator.hasNext())
    {
       print(iterator.next());
    }
*/