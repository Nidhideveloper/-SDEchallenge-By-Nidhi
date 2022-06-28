#include<bits/stdc++.h>
void solve(vector<int> adj[], vector<bool> &vis, int node, stack<int> &st){
    vis[node]=1;
    for(auto it:adj[node]){
        if(!vis[it]){
            solve(adj, vis, it, st);
        }
    }
    st.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &ed, int v, int e)  {
    // Write your code here
    vector<int> adj[v];
    vector<int> ans;
    stack<int> st;
    for(int i=0; i<e; i++){
        adj[ed[i][0]].push_back(ed[i][1]);
    }
    vector<bool> vis(v+1, 0);
    for(int i=0; i<v; i++){
        if(vis[i]==0) solve(adj, vis, i, st);
    }
    while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
    }
    return ans;
}