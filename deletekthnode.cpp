#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int>* removeKthNode(LinkedListNode<int> *head, int k)
{
    // Write your code here.
    LinkedListNode<int>* dummy=new LinkedListNode<int>(1);
    LinkedListNode<int>* slow=dummy;
    LinkedListNode<int>* fast=dummy;
    dummy->next=head;
    if(head==NULL || k==0)
   {
       return head;
   }
    for(int i=1;i<=k;i++){
        fast=fast->next;        
    }
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    slow->next=slow->next->next;
    return dummy->next;
}