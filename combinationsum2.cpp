#include <bits/stdc++.h>
void combSum(vector<int> &a, int k, int ind, vector<vector<int>> &ans, vector<int> &ds){
        
            if(k==0){
                ans.push_back(ds);
                return;
            }
            
        for(int i=ind; i<a.size(); i++){
            if(i>ind && a[i]==a[i-1]) continue;
            if(a[i]>k) break;
            ds.push_back(a[i]);
            combSum(a, k-a[i], i+1, ans, ds);
            ds.pop_back();
        }
        
    }

vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
    vector<vector<int>> ans;
        vector<int> ds;
        sort(arr.begin(), arr.end());
        combSum(arr, target, 0, ans, ds);
        return ans;
}
