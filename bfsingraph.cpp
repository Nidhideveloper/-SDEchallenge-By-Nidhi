#include<bits/stdc++.h>
vector<int> BFS(int V, vector<pair<int, int>> ed)
{
    // Write your code here
    vector<int> adj[V];
    for(int i=0; i<ed.size(); i++){
        adj[ed[i].second].push_back(ed[i].first);
        adj[ed[i].first].push_back(ed[i].second);
    }
    vector<int> ans;
    vector<bool> vis(V, 0);
    for(int i=0; i<V; i++){
        if(!vis[i]){
            queue<int> q;
            q.push(i);
            vis[i]=1;
            sort(adj[i].begin(), adj[i].end());
            while(!q.empty()){
                int node=q.front();
                q.pop();
                ans.push_back(node);
                for(auto it:adj[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=1;
                    }
                }
            }
        }
    }
    return ans;
}