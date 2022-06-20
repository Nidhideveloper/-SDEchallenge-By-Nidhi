#include <bits/stdc++.h>
vector<int> nextGreater(vector<int> &arr, int n) {
    // Write your code here
    vector<int> nge(n, -1);
    stack<int> st;
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && st.top()<=arr[i]) st.pop();
        if(i<n)
            if(!st.empty())
                nge[i]=st.top();
        st.push(arr[i]);
    }
    return nge;
}