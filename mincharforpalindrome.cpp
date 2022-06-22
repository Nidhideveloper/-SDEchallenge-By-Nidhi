#include<bits/stdc++.h>
int minCharsforPalindrome(string str) {
	// Write your code here.
	string s=str+'#';
    reverse(str.begin(), str.end());
    s+=str;
    int n=s.size();
    vector<int> lps(n);
    lps[0]=0;
    for(int i=1; i<n; i++){
        int x=lps[i-1];
        while(s[x]!=s[i]){
            if(x==0){
                x--;
                break;
            }
            x=lps[x-1];
        }
        lps[i]=x+1;
    }
    return str.size()-lps[n-1];
}
