#include <bits/stdc++.h> 

pair<int,int> missingAndRepeating(vector<int> &arr, int n)
{
	// Write your code here
    pair<int, int> p;
    int x=0, y=0, xorr=arr[0];
    for(int i=1; i<n; i++){
        xorr^=arr[i];
    }
    for(int i=1; i<=n; i++){
        xorr^=i;
    }
    int set_bit= xorr & ~(xorr-1);
    for(int i=0; i<n; i++){
        if(arr[i]&set_bit) x=x^arr[i];
        else y=y^arr[i];
    }
    for(int i=1; i<=n; i++){
        if(i&set_bit) x=x^i;
        else y=y^i;
    }
    int x_cnt=0;
    for(int i=0; i<n; i++){
        if(arr[i]==x) x_cnt++;
    }
    if(x_cnt==0){
        p.first=x;
        p.second=y;
        return p;
    }
    p.first=y;
    p.second=x;
    return p;
	
}
