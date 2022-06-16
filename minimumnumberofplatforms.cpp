int calculateMinPatforms(int arr[], int dep[], int n) {
    // Write your code here.
    sort(arr, arr+n);
        sort(dep, dep+n);
        int i=1, j=0;
        int cnt=1, ans=1;
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                cnt++;
                i++;
            }
            else{
                cnt--;
                j++;
            }
            ans=max(cnt, ans);
        }
        return ans;
}