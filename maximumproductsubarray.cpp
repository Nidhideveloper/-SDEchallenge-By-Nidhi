int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
    int mn=1, mx=1;
    int res=INT_MIN;
    for(int i=0; i<n; i++){
        if(arr[i]<0) {
            int temp=mn;
            mn=mx;
            mx=temp;
        }
        mn=min(mn*arr[i], arr[i]);
        mx=max(mx*arr[i], arr[i]);
        res=max(res, mx);
    }
    return res;
}
