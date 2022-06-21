#include <bits/stdc++.h>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    //    Write your code here.
    deque<int> dq;
    vector<int> ans;
    int n=nums.size();
    if(k>n){
        ans.push_back(*max_element(nums.begin(), nums.end()));
        return ans;
    }
    
    int i=0, j=0;
    while(j<n){
        while(!dq.empty() && dq.back()<nums[j]){
            dq.pop_back();
        }
        dq.push_back(nums[j]);
        if(j-i+1 < k) j++;
        else if(j-i+1 == k){
            ans.push_back(dq.front());
            //sliding window
            if(nums[i]==dq.front()){
                dq.pop_front();
            }
            i++; j++;
        }
    }
    return ans;
}