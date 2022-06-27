void dfs(vector<int> adj[], vector<bool> &vis, int i, vector<int> &v){
    v.push_back(i);
    vis[i]=1;
    for(auto it:adj[i]){
        if(vis[it]==0){
            dfs(adj, vis, it, v);
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &ed)
{
    // Write your code here
    vector<int> adj[V];
    for(int i=0; i<E; i++){
        adj[ed[i][0]].push_back(ed[i][1]);
        adj[ed[i][1]].push_back(ed[i][0]);
    }
    vector<vector<int>> ans;
    vector<bool> vis(V, 0);
    for(int i=0; i<V; i++){
        vector<int> v;
        if(vis[i]==0){
            dfs(adj, vis, i, v);
        }
        if(v.size()!=0){
            sort(v.begin(), v.end());
            ans.push_back(v);
        }
    }
    return ans;
}