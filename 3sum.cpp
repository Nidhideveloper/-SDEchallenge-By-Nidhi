#include <bits/stdc++.h> 
vector<vector<int>> findTriplets(vector<int>nums, int n, int k) {
	// Write your code here.
    vector<vector<int>> ans;
        
        if(n==0) return ans;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n-2; i++){
            if(i==0 || (i>0 && nums[i]!=nums[i-1])){
            int l=i+1, r=n-1, req=k-nums[i];
            while(l<r){
                int sum=nums[l]+nums[r];
                if(sum==req){
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[l]);
                    temp.push_back(nums[r]);
                    ans.push_back(temp);
                    while(l<r && nums[l]==nums[l+1]) l++;
                    while(l<r && nums[r]==nums[r-1]) r--;
                    l++;r--;
                }
                else if(sum < req) l++;
                else r--;
                
                
            }
            
            }
        }
        
        return ans;
}