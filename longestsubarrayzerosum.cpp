#include <bits/stdc++.h> 
int LongestSubsetWithZeroSum(vector < int > a) {

  // Write your code here
    unordered_map<int, int> mpp;
    int n=a.size();
        int sum=0, mx=0;
        for(int i=0; i<n; i++){
            sum+=a[i];
            if(sum==0){
                mx=i+1;
            }
            else{
                if(mpp.find(sum)!=mpp.end()){
                    mx=max(mx, i-mpp[sum]);
                    
                }else mpp[sum]=i;
            }
        }
        return mx;
}