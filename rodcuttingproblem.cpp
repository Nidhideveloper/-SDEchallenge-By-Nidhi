#include<bits/stdc++.h>
int cutRod(vector<int> &p, int n)
{
	// Write your code here.
    vector<int> tmp(n);
    for(int i=0; i<n; i++){
        tmp[i]=i+1;
    }
    int dp[n+1][n+1];
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            if(i==0 || j==0) dp[i][j]=0;
            else if(tmp[i-1]<=j) dp[i][j]=max(dp[i][j-tmp[i-1]]+p[i-1], dp[i-1][j]);
            else dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][n];
}
