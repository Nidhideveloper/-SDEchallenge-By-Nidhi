#include <bits/stdc++.h>
void fun(int i, vector<int> &a, vector<int> &temp, vector<vector<int>> &ans){
    if(i==a.size()){
        ans.push_back(temp);
        return;
    }
    
    temp.push_back(a[i]);
    fun(i+1, a, temp, ans);
    temp.pop_back();
    
    while(i+1<a.size() && a[i]==a[i+1]) i++; //to avoid duplicates
    
    fun(i+1, a, temp, ans);
}


vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> temp;
    fun(0, arr, temp, ans);
    sort(ans.begin(), ans.end());
    return ans;
}