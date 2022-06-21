#include<bits/stdc++.h>
class LRUCache
{
public:
    class Node{
        public:
            int key;
        int val;
        Node* next;
        Node* prev;
        Node(int key, int val){
            this->key=key;
            this->val=val;
        }
    };
    Node* head=new Node(-1, -1);
    Node* tail= new Node(-1, -1);
    int cap;
    unordered_map<int, Node*> m;
    
    LRUCache(int capacity)
    {
        // Write your code here
        cap=capacity;
        head->next=tail;
        tail->prev=head;
        
    }
    void add(Node* node){
        Node* tmp = head->next;
        node->next=tmp;
        node->prev=head;
        head->next=node;
        tmp->prev=node;
    }
    void del(Node* node){
        Node* prevv = node->prev;
        Node* nextt = node->next;
        prevv->next=nextt;
        nextt->prev=prevv;
    }
    int get(int key)
    {
        // Write your code here
        if(m.find(key)!=m.end()){
            Node* cur = m[key];
            int res = cur->val;
            m.erase(key);
            del(cur);
            add(cur);
            m[key]=head->next;
            return res;
        }
        return -1;
    }

    void put(int key, int value)
    {
        // Write your code here
        if(m.find(key)!=m.end()){
            Node* node = m[key];
            m.erase(key);
            del(node);
        }
        
        if(m.size()==cap)
        {
            m.erase(tail->prev->key);
            del(tail->prev);
        }
        
        add(new Node(key,value));
        m[key] = head->next;
    }
};
