LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    map<LinkedListNode<int> *,LinkedListNode<int> *>mp;
    int i=0;
    LinkedListNode<int> *ptr = head;
    while(ptr){
        mp[ptr] = new LinkedListNode<int> (ptr->data);
        ptr = ptr->next;
    }
    ptr = head;
    while(ptr){
        mp[ptr]->next = mp[ptr->next];
        mp[ptr]->random = mp[ptr->random];
        ptr = ptr->next;
    }
    return mp[head];
}
