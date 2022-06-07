#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mn=INT_MAX, mx=0;
    for(int i=0; i<prices.size(); i++){
        mn=min(mn, prices[i]);
        mx=max(mx, prices[i]-mn);
    }
    return mx;
}