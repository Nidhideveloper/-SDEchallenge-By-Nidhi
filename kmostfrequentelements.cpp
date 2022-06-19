#include <bits/stdc++.h>
vector<int> KMostFrequent(int n, int k, vector<int> &nums)
{
    // Write your code here.
    unordered_map<int, int> mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;
        for(auto itr:mpp){
            minH.push({itr.second, itr.first});
            if(minH.size() > k){
                minH.pop();
            }
        }
        
        vector<int> ans;
        while(!minH.empty()){
            pair<int, int> x = minH.top();
            ans.push_back(x.second);
            minH.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
}