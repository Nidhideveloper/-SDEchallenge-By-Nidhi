/************************************************************

    Following is the Binary Tree node structure
    
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
class req{
    public:
    int mx;
    int mn;
    int sz;
    bool isBST;
};

req dfs(TreeNode<int> *root, int &res){
    if(root==NULL) return {INT_MIN, INT_MAX, 0, true};
    req l = dfs(root->left, res);
    req r=dfs(root->right, res);
    req node;
    node.sz=l.sz + r.sz+1;
    node.mx=max(root->data, r.mx);
    node.mn=min(root->data, l.mn);
    if(l.isBST && r.isBST && (root->data>l.mx && root->data<r.mn)) node.isBST=true;
    else node.isBST=false;
    if(node.isBST) res=max(res, node.sz);
    return node;
}
int largestBST(TreeNode<int>* root) 
{
    // Write your code here.
    int ans=0;
    req temp=dfs(root, ans);
    return ans;
}
