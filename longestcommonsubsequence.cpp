#include<bits/stdc++.h>
int lcs(string s, string t)
{
	//Write your code here
    int n=s.size(), m=t.size();
    if(n==0 || m==0) return 0;
    int mx=0;
    vector<int> prev(m+1, 0);
    for(int i=0; i<=n; i++){
        vector<int> temp(m+1, 0);
        for(int j=0; j<=m; j++){
            if(i==0 || j==0) temp[j]=0;
            else{
                if(s[i-1]==t[j-1]){
                    temp[j]=1+prev[j-1];
                    mx=max(mx, temp[j]);
                }
                else temp[j]=max(prev[j], temp[j-1]);
            }
        }
        prev=temp;
    }
    return mx;
}