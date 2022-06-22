#include<bits/stdc++.h>
vector<int> lpsfind(string s, int n){
    vector<int> lps(n);
    int len=0, i=1;
    lps[0]=0;
    while(i<n){
        if(s[i]==s[len]){
            len++;
            lps[i]=len;
            i++;
        }else{
            if(len!=0){
                len=lps[len-1];
            }
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
bool findPattern(string p, string s)
{
    // Write your code here.
    int n=s.size(), m=p.size();
    vector<int> ans=lpsfind(p, m);
    int i=0, j=0;
    
    while(i<n){
        if(s[i]==p[j]){
            i++, j++;
        }
        if(j>=m) return true;
        else if(i<n && s[i]!=p[j]){
            if(j!=0) j=ans[j-1];
            else i++;
        }
    }
    return false;
}