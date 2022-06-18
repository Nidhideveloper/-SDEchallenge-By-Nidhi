int solve(vector<int> &row, int mid){
    int l=0, r=row.size()-1;
    while(l<=r){
        int m=(l+r)>>1;
        if(row[m]<=mid){
            l=m+1;
        }
        else r=m-1;
    }
    return l;
}
int getMedian(vector<vector<int>> &A)
{
    // Write your code here.
    int l=1, r=1e9;
    int n=A.size();
    int m=A[0].size();
    while(l<=r){
        int mid=l+(r-l)/2;
        int cnt=0;
        for(int i=0; i<n; i++){
            cnt+=solve(A[i], mid);
        }
        if(cnt <= (m*n)/2) l=mid+1;
        else r=mid-1;
    }
    return l;
}