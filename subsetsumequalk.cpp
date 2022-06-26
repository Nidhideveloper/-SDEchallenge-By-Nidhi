#include<bits/stdc++.h>
bool solve(int i, int sum, vector<int> &a, vector<vector<int>> &dp){
    if(sum==0) return true;
    if(i==0) return a[0]==sum;
    if(dp[i][sum]!=-1) return dp[i][sum];
    bool flag=0, notflag=0;
    if(a[i]<=sum) flag=solve(i-1, sum-a[i], a, dp);
    notflag=solve(i-1, sum, a, dp);
    return dp[i][sum]=flag|notflag;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
    return solve(n-1, k, arr, dp);
}