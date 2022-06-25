/**********************************************************

    Following is the Binary Tree Node structure:

    template <typename T>
    class BinaryTreeNode {
        public: 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }

        ~BinaryTreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };
***********************************************************/
void help(BinaryTreeNode<int> *root, vector<int> &a){
    if(root==NULL) return;
    help(root->left, a);
    a.push_back(root->data);
    help(root->right, a);
}

bool pairSumBst(BinaryTreeNode<int> *root, int k)
{
    // Write your code here
    if(root==NULL) return false;
    vector<int> a;
    help(root, a);
    int i=0, j=a.size()-1;
    while(i<j){
        if(a[i]+a[j]==k){
            return true;
            break;
        }
        else if(a[i]+a[j]>k) j--;
        else i++;
    }
    return false;
}