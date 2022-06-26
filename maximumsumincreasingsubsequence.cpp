#include<bits/stdc++.h>
int maxIncreasingDumbbellsSum(vector<int> &r, int n)
{
	// Write your code here
    vector<int> dp(n, -1);
    dp[0]=r[0];
    for(int i=1; i<n; i++){
        int req=r[i];
        for(int j=0; j<i; j++){
            if(r[j]<r[i]) req=max(req, r[i]+dp[j]);
        }
        dp[i]=req;
    }
    return *max_element(dp.begin(), dp.end());
}