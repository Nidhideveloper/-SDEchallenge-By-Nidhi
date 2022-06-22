#include<bits/stdc++.h>
string reverseString(string s)
{
    // Write your code here.
    vector<string> v;
    
    int start=0, cnt=0;
    for(int i=0; i<s.size(); i++){
        start=i;
        if(s[i]!=' '){
            cnt=0;
            while(s[i]!=' '){
            cnt++; i++;}
            v.push_back(s.substr(start, cnt));
        }
        
    }
    string ans="";
    for(int i=v.size()-1; i>=0; i--){
        ans.append(v[i]);
        ans.append(" ");
    }
    return ans;
    
}