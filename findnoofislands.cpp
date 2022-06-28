void solve(int **a, int n, int m, int i, int j){
    if(i>=n || j>=m || i<0 || j<0 || a[i][j]!=1) return;
    a[i][j]=2;
    solve(a,n, m, i+1, j);
    solve(a, n, m, i, j+1);
    solve(a, n, m, i-1, j);
    solve(a, n, m, i, j-1);
    solve(a, n, m, i+1, j+1);
    solve(a, n, m, i+1, j-1);
    solve(a, n, m, i-1, j+1);
    solve(a, n, m, i-1, j-1);
}

int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
    int ans=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(arr[i][j]==1) {
                solve(arr, n, m, i, j);
                ans++;
            }
        }
    }
    return ans;
}
