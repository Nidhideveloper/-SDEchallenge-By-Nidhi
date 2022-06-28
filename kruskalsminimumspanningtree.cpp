#include<bits/stdc++.h>

bool comp(vector<int> &a, vector<int> &b){
    return a[2]<b[2];
}

int findparent(int node, vector<int> &par){
    if(node==par[node]) return node;
    return par[node]=findparent(par[node], par);
}

void unionn(int u, int v, vector<int> &rank, vector<int> &par){
    if(rank[u]<rank[v]) par[u]=v;
    else if(rank[v]<rank[u]) par[v]=u;
    else{
        par[v]=u;
        rank[u]++;
    }
}

int kruskalMST(int n, int m, vector<vector<int>> &g) {
	// Write your code here.
    sort(g.begin(), g.end(), comp);
    int cost=0;
    vector<int> par(n+1);
    for(int i=1; i<=n; i++) par[i]=i;
    vector<int> rank(n+1, 0);
    for(auto it:g){
        if(findparent(it[0], par)!=findparent(it[1], par)){
            cost+=it[2];
            unionn(findparent(it[0], par), findparent(it[1], par), rank, par);
        }
    }
    return cost;
}