int kthLargest(vector<int>& arr, int n, int k)
{
	// Write your code here.
    priority_queue<int> mxH;
    for(int i=0; i<n; i++){
        mxH.push(arr[i]);
    }
    while(mxH.size()>n-k+1) mxH.pop();
    return mxH.top();
}