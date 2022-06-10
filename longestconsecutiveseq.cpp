#include <bits/stdc++.h> 
int lengthOfLongestConsecutiveSequence(vector<int> &nums, int n) {
    // Write your code here.
    int sz=nums.size();
        if(sz==0) return 0;
        if(sz==1) return 1;
        
        sort(nums.begin(), nums.end());
        int ans=1, cur=1;
        int prev=nums[0];
        for(int i=1; i<sz; i++){
            if(nums[i]==prev+1) cur++;
            else if(nums[i]!=prev){
                cur=1;
            }
            prev=nums[i];
            ans=max(ans, cur);
        }
        
        return ans;
}