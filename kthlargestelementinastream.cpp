#include<bits/stdc++.h>
class Kthlargest {
public:
    priority_queue<int, vector<int>, greater<int>> mnH;
    int sz;
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
        sz=k;
        for(int i=0; i<arr.size(); i++){
            mnH.push(arr[i]);
            if(mnH.size()>k) mnH.pop();
        }
    }

    void add(int num) {
        // Write your code here.
        mnH.push(num);
        if(mnH.size()>sz) mnH.pop();
    }

    int getKthLargest() {
       // Write your code here.
        int topp=mnH.top();
        return topp;
    }

};