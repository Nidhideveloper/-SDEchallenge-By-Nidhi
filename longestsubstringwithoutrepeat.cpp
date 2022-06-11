#include <bits/stdc++.h> 
int uniqueSubstrings(string s)
{
    //Write your code here
    if(s.length()==0||s.length()==1) return s.length();
        unordered_map<char, int> mpp;
        int i=0, j=0, mx=0;
        while(j<s.size()){
            mpp[s[j]]++;
            if(mpp.size() == (j-i+1)){
                 //possible answer
                mx=max(mx,j-i+1);
                j++;
            }
            else if(mpp.size()<(j-i+1)){
                while(mpp.size()<(j-i+1)){
                    mpp[s[i]]--;
                    if(mpp[s[i]]==0) mpp.erase(s[i]);
                    i++;
                }
                j++;
            }
        }
        return mx; 
}