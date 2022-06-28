#include<bits/stdc++.h>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
     vector<pair<int, int>> adj[n+1];
    for(auto it:g){
        auto x=it.first;
        adj[x.first].push_back({x.second, it.second});
        adj[x.second].push_back({x.first, it.second});
    }
    vector<int> par(n+1, -1);
    vector<int> mst(n+1, 0);
    vector<int> ans(n+1, INT_MAX);
    ans[1]=0;
    for(int i=0; i<n-1; i++){
        int mn=INT_MAX, u;
        for(int j=1; j<=n; j++){
            if(mst[j]==0 && ans[j]<mn) mn=ans[j], u=j;
        }
    
    mst[u]=1;
    for(auto it:adj[u]){
        int x=it.first;
        int wt=it.second;
        if(mst[x]==0 && wt<ans[x]){
            ans[x]=wt;
            par[x]=u;
        }
    }
    }
    vector<pair<pair<int, int>, int>> res;
    for(int i=1; i<=n; i++){
        if(par[i]!=-1) res.push_back({{i, par[i]}, ans[i]});
    }
    return res;
}
