#include<bits/stdc++.h>
int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &ed) {
    // Write your code here.
    vector<bool> vis(n+1, 0);
    vector<int> ans(n+1, INT_MAX);
    ans[src]=0;
    for(int i=0; i<=n; i++){
        for(int j=0; j<m; j++){
            if(ans[ed[j][0]]!=INT_MAX && ans[ed[j][0]]+ed[j][2]<ans[ed[j][1]]){
                ans[ed[j][1]]=ans[ed[j][0]]+ed[j][2];
            }
        }
    }
    if(ans[dest]==INT_MAX) return 1e9;
    return ans[dest];
}