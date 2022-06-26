#include<bits/stdc++.h>

int mcm(vector<int> &a, int i, int j, vector<vector<int>> &dp){
    int mn=INT_MAX;
    if(i>=j) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    for(int ind=i; ind<j; ind++){
        int l=mcm(a, i, ind, dp)+mcm(a, ind+1, j, dp)+a[i-1]*a[ind]*a[j];
        mn=min(mn, l);
    }
    return dp[i][j]=mn;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    // Write your code here.
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return mcm(arr, 1, N-1, dp);
}