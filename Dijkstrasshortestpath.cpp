vector<int> dijkstra(vector<vector<int>> &vec, int v, int e, int s) {
    // Write your code here.
    vector<pair<int, int>> adj[v];
    for(int i=0; i<e; i++){
        adj[vec[i][0]].push_back({vec[i][1], vec[i][2]});
        adj[vec[i][1]].push_back({vec[i][0], vec[i][2]});
    }
    vector<int> ans(v, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> mnH;
    ans[s]=0;
    mnH.push({0, s});
    while(!mnH.empty()){
        int node=mnH.top().second;
        int x=mnH.top().first;
        mnH.pop();
        for(auto it:adj[node]){
            if(x+it.second<ans[it.first]){
                ans[it.first]=x+it.second;
                mnH.push({ans[it.first], it.first});
            }
        }
    }
    return ans;
}
