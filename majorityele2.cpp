#include <bits/stdc++.h> 
vector<int> majorityElementII(vector<int> &nums)
{
    // Write your code here.
    if(nums.size()==1) return nums;
        //voting algo 
        
        int el1=-1, el2=-1, cnt1=0, cnt2=0;
        int n=nums.size();
        for(int i=0; i<n; i++){
            if(el1==nums[i]){
                cnt1++;
            }
            else if(el2==nums[i]){
                cnt2++;
            }
            else if(cnt1==0){
                cnt1=1;
                el1=nums[i];
            }
            else if(cnt2==0){
                cnt2=1;
                el2=nums[i];
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1=0, cnt2=0;
        for(int i=0; i<n; i++){
            if(nums[i]==el1) cnt1++;
            else if(nums[i]==el2) cnt2++;
        }
        vector<int> ans;
        if(cnt1>n/3) ans.push_back(el1);
        if(cnt2>n/3 && el1!=el2) ans.push_back(el2);
        return ans;
}