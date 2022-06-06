#include <bits/stdc++.h> 
vector<int> nextPermutation(vector<int> &permutation, int n)
{
    //  Write your code here.
    int i, k;
    for(i=n-2; i>=0; i--){
        if(permutation[i]<permutation[i+1]) break;
    }
    if(i<0){
        reverse(permutation.begin(), permutation.end());
        return permutation;
    }
    for(k=n-1; k>i; k--){
        if(permutation[k] > permutation[i]) break;
    }
    swap(permutation[i], permutation[k]);
    reverse(permutation.begin()+i+1, permutation.end());
    return permutation;
}