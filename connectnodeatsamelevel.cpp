/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/
#include<bits/stdc++.h>
void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    if(root==NULL) return;
    queue<BinaryTreeNode< int >*> q;
    q.push(root);
    while(!q.empty()){
        int sz=q.size();
        BinaryTreeNode< int > *prev=NULL;
        BinaryTreeNode< int > *temp=q.front();
        q.pop();
        while(sz--){
            if(temp->left){
                if(!prev) prev=temp->left;
                else{
                    prev->next=temp->left;
                    prev=temp->left;
                }
                q.push(temp->left);
            }
            if(temp->right){
                if(prev==NULL) prev=temp->right;
                else{
                    prev->next=temp->right;
                    prev=temp->right;
                }
                q.push(temp->right);
            }
            if(!q.empty() && sz!=0){
                temp=q.front();
                q.pop();
            }
        }
    }
}