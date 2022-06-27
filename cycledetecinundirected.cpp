#include<bits/stdc++.h>

bool isCycle(vector<int> adj[], int i, vector<bool>&vis, int par){
    vis[i]=1;
    for(auto it:adj[i]){
        if(!vis[it]){
            if(isCycle(adj, it, vis, i)){
                return 1;
            }
        }
        else if(it!=par){
            return 1;
        }
    }
    return 0;
}

string cycleDetection (vector<vector<int>>& ed, int n, int m)
{
    // Write your code here.
    vector<int> adj[n+1];
    for(int i=0; i<m; i++){
        adj[ed[i][0]].push_back(ed[i][1]);
        adj[ed[i][1]].push_back(ed[i][0]);
    }
    //vector<vector<int>> ans;
    vector<bool> vis(n+1, 0);
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            if(isCycle(adj, i, vis, -1)) return "Yes";
        }
    }
    return "No";
}
