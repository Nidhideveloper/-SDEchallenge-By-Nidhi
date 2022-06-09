#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
    if(m==0) return false;
    int low=0, high=(m*n)-1;
    while(low<=high){
        int mid=(low + (high-low)/2);
        if(mat[mid/n][mid%n]==target) return true;
        if(mat[mid/n][mid%n] < target) low=mid+1;
        else high=mid-1;
    }
    return false;
}