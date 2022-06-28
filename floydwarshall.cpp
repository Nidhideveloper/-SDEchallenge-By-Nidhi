int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &ed) {
    // Write your code here.
    vector<vector<int>> tmp(n+1, vector<int>(n+1, 1e9));
    for(auto it:ed){
        tmp[it[0]][it[1]]=it[2];
    }
    int node=1;
    while(node<=n){
        tmp[node][node]=0;
        node++;
    }
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
                if(tmp[j][i]==1e9 || tmp[i][k]==1e9) continue;
                tmp[j][k]=min(tmp[j][k], tmp[j][i]+tmp[i][k]);
            }
        }
    }
    return tmp[src][dest];
}