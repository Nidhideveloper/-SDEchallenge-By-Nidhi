#include <bits/stdc++.h> 

void rotateMatrix(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here
        
    int row=0, col=0;
    int prev, cur;
    while(row<n && col<m){
        if(row+1==n || col+1==m) break;
        prev=mat[row+1][col];
        for(int i=col; i<m; i++){
            cur=mat[row][i];
            mat[row][i]=prev;
            prev=cur;
        }
        row++;
        for(int i=row; i<n; i++){
            cur=mat[i][m-1];
            mat[i][m-1]=prev;
            prev=cur;
        }
        m--;
        if(row<n){
            for(int i=m-1; i>=col; i--){
                cur=mat[n-1][i];
                mat[n-1][i]=prev;
                prev=cur;
            }
            
        }
        n--;
        if(col<m){
            for(int i=n-1; i>=row; i--){
                cur=mat[i][col];
                mat[i][col]=prev;
                prev=cur;
            }
        }
        col++;
    }

}