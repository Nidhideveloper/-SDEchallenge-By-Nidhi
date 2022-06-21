#include<bits/stdc++.h>
// Implement class for minStack.
class minStack
{
	// Write your code here.
	private: 
    int topp;
   int size;
   int *mini;
   int *arr;
	public:
		
		// Constructor
		minStack() 
		{ 
			// Write your code here.
            size=10000001;
           topp=-1;
           arr=new int[size];
           mini=new int[size];
		}
		
		// Function to add another element equal to num at the top of stack.
		void push(int val)
		{
			// Write your code here.
             topp=topp+1;
  arr[topp]=val;
          if(topp==0)
              mini[topp]=val;
        else
            mini[topp]=min(mini[topp-1],val);
		}
		
		// Function to remove the top element of the stack.
		int pop()
		{
			// Write your code here.
            if(topp==-1)return -1;
           else
           {
               return arr[topp--];
           }
        }
		
		// Function to return the top element of stack if it is present. Otherwise return -1.
		int top()
		{
			// Write your code here.
            if(topp==-1)return -1;
           else return arr[topp];
		}
		
		// Function to return minimum element of stack if it is present. Otherwise return -1.
		int getMin()
		{
			// Write your code here.
              return (topp==-1)?-1:mini[topp];
        
		}
};