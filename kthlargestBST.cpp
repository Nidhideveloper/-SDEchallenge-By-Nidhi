/************************************************************
    Following is the Binary Search Tree node structure
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
//int val=0;
//int res=-1;
void traverse(TreeNode<int> *root, int &val, int &res){
    if(root==NULL) return;
    traverse(root->right, val, res);
    val--;
    if(val==0){
        res=root->data;
        return;
    }
    traverse(root->left, val, res);
}
int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    int val=k;
    int res=-1;
    traverse(root, val, res);
    return res;
}
