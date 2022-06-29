#include<bits/stdc++.h>
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> tmp;
    tmp.push_back(arr[0]);
    int ans=1;
    for(int i=1; i<n; i++){
        if(arr[i]>tmp.back()){
            tmp.push_back(arr[i]);
            ans++;
        }
        else{
            int index=lower_bound(tmp.begin(), tmp.end(), arr[i])-tmp.begin();
            tmp[index]=arr[i];
        }
    }
    return ans;
}
