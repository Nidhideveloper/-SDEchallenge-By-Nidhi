int minSumPath(vector<vector<int>> &g) {
    // Write your code here.
    int n=g.size(), m=g[0].size();
    int dp[n][m]={0};
    dp[0][0]=g[0][0];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(i!=0 || j!=0){
                int up=g[i][j];
                if(i>0) up+=dp[i-1][j];
                else up+=1e9;
                int l=g[i][j];
                if(j>0) l+=dp[i][j-1];
                else l+=1e9;
                dp[i][j]=min(l, up);
            }
        }
    }
    return dp[n-1][m-1];
    
}