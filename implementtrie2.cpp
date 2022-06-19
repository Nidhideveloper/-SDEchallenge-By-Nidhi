struct node{
   int end=0;
   int p=0;
   node *next[26];
};
class Trie{
node *root;
   public:
   Trie(){
       // Write your code here.
       root=new node();
   }
   void insert(string &s){
       // Write your code here.
       node *head=root;
       for(int i=0;i<s.size();i++){
           if(!head->next[s[i]-'a'])
               head->next[s[i]-'a']=new node();
           head->next[s[i]-'a']->p++;
           head=head->next[s[i]-'a'];
       }
       head->end++;
   }
   int countWordsEqualTo(string &s){
       // Write your code here.
       node *head=root;
       for(int i=0;i<s.size();i++){
           if(!head->next[s[i]-'a']) return 0;
           head=head->next[s[i]-'a'];
       }
       return head->end;
   }
   int countWordsStartingWith(string &s){
       // Write your code here.
       node *head=root;
       for(int i=0;i<s.size();i++){
           if(!head->next[s[i]-'a']) return 0;
           head=head->next[s[i]-'a'];
       }
       return head->p;
   }
   void erase(string &s){
       // Write your code here.
       node *head=root;
       for(int i=0;i<s.size();i++){
           if(!head->next[s[i]-'a']) return;
           head->next[s[i]-'a']->p--;
           head=head->next[s[i]-'a'];
       }
       head->end--;
   }
};
