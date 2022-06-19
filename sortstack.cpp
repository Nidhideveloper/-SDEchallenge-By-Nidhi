#include <bits/stdc++.h>
void sortStack(stack<int> &s)
{
	// Write your code here
    stack<int> temp;
   while(!s.empty()){
       int x = s.top();
       s.pop();
       while(!temp.empty() && temp.top()>x){
           s.push(temp.top());
           temp.pop();
       }
       temp.push(x);
   }
   s = temp;
    
}