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
void traverse(TreeNode<int> *root, int &val, int &res){
    if(root==NULL) return;
    traverse(root->left, val, res);
    val--;
    if(val==0){
        res=root->data;
        return;
    }
    traverse(root->right, val, res);
}
int kthSmallest(TreeNode<int> *root, int k)
{
	//	Write the code here.
    int val=k;
    int res=-1;
    traverse(root, val, res);
    return res;
}