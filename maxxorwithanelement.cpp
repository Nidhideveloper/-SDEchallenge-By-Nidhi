#include <bits/stdc++.h>
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &q){
	//	Write your coode here.
    sort(arr.begin(), arr.end());
    vector<int> ans;
    for(int i=0; i<q.size(); i++){
        int xorr = q[i][0];
        int limit = q[i][1];
        int mx=-1;
        for(int j=0; j<arr.size(); j++){
            if(arr[j]>limit) break;
            else{
                int res = xorr^arr[j];
                mx=max(mx, res);
            }
        }
        ans.push_back(mx); }
    return ans;
}