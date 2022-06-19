#include <bits/stdc++.h>
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<int,vector<int>,greater<int>> minH;
    for(auto it : kArrays){
        for(auto x:it) minH.push(x);
    }
    vector<int> res;
    while(!minH.empty()){
        res.push_back(minH.top());
        minH.pop();
    }
    return res;
}
