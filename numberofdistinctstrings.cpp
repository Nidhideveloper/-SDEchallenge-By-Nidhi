class Node {
    public:
    Node *charr[26];
    int wc = 0, pc=0;
    bool end = false;
    bool hascheck(char ch){
        return charr[ch-'a']!=NULL;
    }
    Node* get(char ch){
        return charr[ch-'a'];
    }
    void insert(char ch){
        charr[ch - 'a'] = new Node();
    }
};

class Trie{
    private:
    Node *root;
    int cnt=0;
    public:
        Trie(){
            root=new Node();
            cnt=0;
        }
    Node* insertop(string s){
        Node* node = root;
        for(int i=0; i<s.size(); i++){
            if(!node->hascheck(s[i])){
                node->insert(s[i]);
                cnt++;
            }
            node = node->get(s[i]);
        }
        node->end = true;
        return node;
    }
    
    int getcnt(){
        return cnt;
    }
};
int distinctSubstring(string &s) {
    //  Write your code here.
    Trie tr;
    int sz=s.size();
    for(int i=0; i<sz; i++){
        tr.insertop(s.substr(i, sz-i));
    }
    return tr.getcnt();
}
