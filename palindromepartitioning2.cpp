#include<bits/stdc++.h>
int palindromePartitioning(string str) {
    // Write your code here
    int n=str.size();
    bool dp[n][n]={0};
    for(int i=0; i<n; i++){
        for(int j=0, k=i; k<n; j++, k++){
            if(i==0){
                dp[j][k]=1;
            }
            else if(i==1){
                if(str[j]==str[k]) dp[j][k]=1;
                else dp[j][k]=0;
            }
            else{
                if(str[j]==str[k] && dp[j+1][k-1]) dp[j][k]=1;
                else dp[j][k]=0;
            }
        }
    }
    int *pt=new int[n]();
    pt[0]=0;
    for(int j=1; j<n; j++){
        int mn=INT_MAX;
        for(int i=j; i>=0; i--){
            if(dp[i][j]==1){
                int tmp;
                if(i==0){
                    tmp=pt[0];
                }
                else tmp=pt[i-1]+1;
                mn=min(mn, tmp);
            }
        }
        pt[j]=mn;
    }
    return pt[n-1];
}
