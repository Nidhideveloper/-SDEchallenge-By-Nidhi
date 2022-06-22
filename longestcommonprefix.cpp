#include <bits/stdc++.h>
string longestCommonPrefix(vector<string> &str, int n)
{
    // Write your code here
    string ans="";
        sort(str.begin(), str.end());
        string s1=str[0];
        string s2=str[str.size()-1];
        for(int i=0; i<min(s1.size(), s2.size()); i++){
            if(s1[i]==s2[i]){
                ans+=s1[i];
            }
            else break;
        }
        return ans;
}


