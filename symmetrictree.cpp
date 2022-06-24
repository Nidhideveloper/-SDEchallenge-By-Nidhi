bool isSame(BinaryTreeNode<int>* p , BinaryTreeNode<int>* q){
        if(p==NULL || q==NULL) return (p==q);
        return (p->data == q->data) && isSame(p->left, q->right) && isSame(p->right, q->left);
    }
bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here. 
    if(root==NULL) return true;
        return isSame(root->left,  root->right);
}