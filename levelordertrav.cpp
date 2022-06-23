/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int> v;
        if(root==NULL) return v;
        queue<BinaryTreeNode<int>*> q;
        q.push(root);
        while(!q.empty()){
            int size=q.size();
            //vector<int> level;
            for(int i=0; i<size; i++){
                BinaryTreeNode<int>* node = q.front();
                q.pop();
                if(node->left != NULL) q.push(node->left);
                if(node->right != NULL) q.push(node->right);
                v.push_back(node->val);
            }
            //v.push_back(level);
        }
        return v;
}