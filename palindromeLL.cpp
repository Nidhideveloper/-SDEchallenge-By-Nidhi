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

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    vector<int> num;       
    while(head != NULL)
    {
        num.push_back(head -> data);        
        head = head -> next;               
    }
    bool flag = true;                        
    int ptr = 0;              
    int ptr2 = num.size() - 1;             
    while(ptr < ptr2)
    {
        if(num[ptr] != num[ptr2])            
        {
            flag = false;
            break;
        }
        ptr++;
        ptr2--;
    }
    return flag;
}