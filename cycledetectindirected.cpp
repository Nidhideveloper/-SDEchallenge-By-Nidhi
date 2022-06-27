#include<bits/stdc++.h>
bool dfs(vector<int> adj[], vector<bool> &vis, int i, vector<int> &ans){
    vis[i]=1;
    ans[i]=1;
    for(auto it:adj[i]){
        if(vis[it]==0){
            if(dfs(adj, vis, it, ans)) return 1;
        }
        else if(ans[it]==1) return 1;
    }
    ans[i]=0;
    return 0;
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & ed) {
  // Write your code here.
    vector<int> adj[n+1];
    for(int i=0; i<ed.size(); i++){
        //adj[ed[i].second].push_back(ed[i].first);
        adj[ed[i].first].push_back(ed[i].second);
    }
    vector<int> ans(n+1, 0);
    vector<bool> vis(n+1, 0);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(dfs(adj, vis, i, ans)) return 1;
        }
    }
    return 0;
}