truct Node{
    Node* arr[2];
    bool contains(int num){
        return (arr[num]!=NULL);
    }
    Node* get(int num){
        return (arr[num]);
    }
    void put(int num, Node* node){
        arr[num]=node;
    }
};

class Trie{
    private:
        Node* root;
    public:
        Trie(){
            root = new Node();
        }
    
    void insert(int num){
        Node* node = root;
        for(int i=31; i>=0; i--){
            int a = (num>>i)&1;
            if(!node->contains(a)){
                node->put(a, new Node());
            }
            node = node->get(a);
        }
    }
    
    int getXor(int n)
               {
                   Node* node=root;
        int mx=0;
        for(int i=31; i>=0; i--){
            int bit = (n>>i)&1;
            if(node->contains(1-bit)){
                mx=mx|(1<<i);
                node=node->get(1-bit);
            }else{
                node=node->get(bit);
            }
        }
        return mx;
               }
};
int maximumXor(vector<int> A)
{
    // Write your code here.
    Trie tr;
    for(int i=0; i<A.size(); i++){
        tr.insert(A[i]);
    }
    int ans=0;
    for(int i=0; i<A.size(); i++){
        ans=max(ans, tr.getXor(A[i]));
    }
     return ans;
}