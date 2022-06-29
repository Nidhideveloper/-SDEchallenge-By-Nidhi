#include<bits/stdc++.h>
void dfs(int n, stack<int> &st, vector<bool> &vis, vector<int> adj[]){
    vis[n]=1;
    for(auto it:adj[n]){
        if(!vis[it]) dfs(it, st, vis, adj);
    }
    st.push(n);
}
void rvrs(int n, vector<int> &a, vector<bool> &vis, vector<int> t[]){
    vis[n]=1;
    a.push_back(n);
    for(auto it:t[n]){
        if(!vis[it]) rvrs(it, a, vis, t);
    }
}

vector<vector<int>> stronglyConnectedComponents(int n, vector<vector<int>> &ed)
{
    // Write your code here.
    vector<int> adj[n];
    for(auto it:ed){
        adj[it[0]].push_back(it[1]);
    }
    stack<int> st;
    vector<bool> vis(n, 0);
    for(int i=0; i<n; i++){
        if(!vis[i]) dfs(i, st, vis, adj);
    }
    vector<int> t[n];
    for(int i=0; i<n; i++){
        vis[i]=0;
        for(auto it:adj[i]) t[it].push_back(i);
    }
    vector<vector<int>> ans;
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!vis[node]){
            vector<int> tmp;
            rvrs(node, tmp, vis, t);
            ans.push_back(tmp);
        }
    }
    return ans;
}