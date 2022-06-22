#include<bits/stdc++.h>

vector<int> zimplementation(string s){
    int n = s.length();
     int l = 0, r = 0;
     
     vector<int> z(n, 0);
     for(int i = 1; i < n; i++)
     {
         if(i > r)
         {
             l = r = i;
             while(r < n && s[r] == s[r - l])
                 r++;
             
             z[i] = (r - l);
             r--;
         }
         else
         {
             int idx = (i - l);
             if(i + z[idx] <= r)
             {
                 z[i] = z[idx];
             }
             else
             {
                 l = i;
                 while(r < n && s[r] == s[r - l])
                     r++;
                 
                 z[i] = (r - l);
                 r--;
             }
         }
     }
     
     return z; 
}
int zAlgorithm(string s, string p, int n, int m)
{
	// Write your code here
    string tmp=p+'#'+s;
    vector<int> ans=zimplementation(tmp);
    vector<int> v;
    int res=0;
    for(int i=0; i<ans.size(); i++){
        if(ans[i]==p.size()){
            int remove=i-p.size()-1;
            v.push_back(remove);
        }
    }
    return (int)v.size();
}