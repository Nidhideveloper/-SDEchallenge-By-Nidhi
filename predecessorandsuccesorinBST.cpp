/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

*************************************************************/

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key)
{
    // Write your code here.
    int pred=-1, suc=-1;
    while(root){
        if(root->data==key){
            break;
        }
        if(root->data>key){
            suc=root->data;
            root=root->left;
        }
        else{
            pred=root->data;
            root=root->right;
        }
    }
    BinaryTreeNode<int> *predr=root->left;
    BinaryTreeNode<int> *sucr=root->right;
    if(predr){
        pred=predr->data;
        while(predr->right){
            predr=predr->right;
            pred=predr->data;
        }
    }
    if(sucr){
        suc=sucr->data;
        while(sucr->left){
            sucr=sucr->left;
            suc=sucr->data;
        }
    }
    return {pred, suc};
}
