#include<bits/stdc++.h>

bool solve(int node, vector<int> adj[], vector<int> &color){
    queue<int> q;
    q.push(node);
    color[node]=1;
    while(!q.empty()){
        int newnode=q.front();
        q.pop();
        for(auto it:adj[newnode]){
            if(color[it]==-1){
                color[it]=1-color[newnode];
                q.push(it);
            }
            else if(color[it]==color[newnode]) return 0;
        }
    }
    return 1;
}

bool isGraphBirpatite(vector<vector<int>> &ed) {
	// Write your code here.
    int n=ed.size();
    vector<int> adj[n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(ed[i][j]==1){
            adj[i].push_back(j);
            adj[j].push_back(i);}
        }
    }
    vector<int> color(n, -1);
    for(int i=0; i<n; i++){
        if(color[i]==-1) 
            if(solve(i, adj, color)==0) return 0;
    }
      return 1;
}