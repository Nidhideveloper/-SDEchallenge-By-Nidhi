#include <bits/stdc++.h>
vector<int> findSpans(vector<int> &price) {
    // Write your code here.
    stack<int> st;
    int n=price.size();
    vector<int> ans(n, 1);
    for(int i=0; i<n; i++){
        int cnt=1;
        if(!st.empty() && price[i]>=price[st.top()]){
            while(!st.empty() && price[i]>=price[st.top()]){
                cnt+=ans[st.top()];
                st.pop();
            }
        }
        st.push(i);
        ans[i]=cnt;
    }
    return ans;
}