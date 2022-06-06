#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    /*
        Don't write main().
        Don't read input, it is passed as function argument.    
        No need to print anything.
        Taking input and printing output is handled automatically.
    */
    if(n==0) return 0;
    long long mx=0;
    long long sum=0;
    for(int i=0; i<n; i++){
        sum += arr[i];
        mx = max(mx, sum);
        if(sum<0) sum=0;
    }
    return mx;
}