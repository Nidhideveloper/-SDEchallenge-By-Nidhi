#include<bits/stdc++.h>
vector<int> findMedian(vector<int> &arr, int n){
	
	// Write your code here 
    vector<int> ans;
    priority_queue<int> mxH;
    priority_queue<int, vector<int>, greater<int>> mnH;
    for(int i=0; i<n; i++){
        if(i%2==0){
            mnH.push(arr[i]);
            mxH.push(mnH.top());
            mnH.pop();
            ans.push_back(mxH.top());
        }
        else{
            mxH.push(arr[i]);
            mnH.push(mxH.top());
            mxH.pop();
            ans.push_back((mxH.top()+mnH.top())/2);
        }
    }
    return ans;
}
