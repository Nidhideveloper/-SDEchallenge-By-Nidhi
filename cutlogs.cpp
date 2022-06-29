#include<bits/stdc++.h>
vector<vector<int>> dp(15, vector<int>(1, 0));
void solve(){
    for(int i=0; true; i++){
        int cur=dp[3][i]+(i*(i+1))/2+1;
        dp[3].push_back(cur);
        if(cur>10000) break;
    }
    for(int i=4; i<=14; i++){
        for(int j=0; true; j++){
            int cur=dp[i][j]+dp[i-1][j]+1;
            dp[i].push_back(cur);
            if(cur>10000) break;
        }
    }
}
int cutLogs(int k, int n)
{
    // Write your code here.
    if(k==1) return n;
    if(k==2) return ceil((-1.0+sqrt(1+8*n))/2.0);
    if(dp[3].size()==1) solve();
    k = min(k, 14);
    int ind=lower_bound(dp[k].begin(), dp[k].end(), n)-dp[k].begin();
    return ind;
    
}
