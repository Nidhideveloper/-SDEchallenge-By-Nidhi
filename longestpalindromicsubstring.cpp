#include<bits/stdc++.h>
string longestPalinSubstring(string s)
{
    // Write your code here.
    int n=s.size();
    if(n<=1) return s;
    int mx=1, start=0, end=0;
    
    //for odd len
    for(int i=0; i<n-1; i++){
        int l=i, r=i;
        while(l>=0 && r<n){
            if(s[l]==s[r]){
                l--; r++;
            }
            else break;
        }
        int len=r-l-1;
        if(len>mx){
            mx=len;
            start=l+1, end=r-1;
        }
    }
    
    //even len pal
    for(int i=0; i<n-1; i++){
        int l=i, r=i+1;
        while(l>=0 && r<n){
            if(s[l]==s[r]){
                l--; r++;
            }
            else break;
            
        }
        int len=r-l-1;
        if(len>mx){
            mx=len;
            start=l+1, end=r-1;
        }
    }
    return s.substr(start, mx);
}