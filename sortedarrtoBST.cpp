/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
TreeNode<int> *dfs(vector<int> &a, int l, int r){
    if(l>r) return NULL;
    int mid=(l+r)>>1;
    TreeNode<int> *cur=new TreeNode<int>(a[mid]);
    cur->left=dfs(a, l, mid-1);
    cur->right=dfs(a, mid+1, r);
    return cur;
}
TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
    if(n==0) return NULL;
    return dfs(arr, 0, n-1);
}