#include<bits/stdc++.h>
bool wordBreak(vector < string > & arr, int n, string & t) {
    // Write your code here.
    if(arr.size()==0) return false;
    vector<bool> dp(t.size()+1, 0);
    dp[0]=1;
    for(int i=1; i<=t.size(); i++){
        for(int j=i-1; j>=0; j--){
            if(dp[j]==1){
                string ans=t.substr(j, i-j);
                auto it=find(arr.begin(), arr.end(), ans);
                if(it!=arr.end()){
                    dp[i]=1;
                    break;
                }
            }
        }
    }
    return dp[t.size()];
}