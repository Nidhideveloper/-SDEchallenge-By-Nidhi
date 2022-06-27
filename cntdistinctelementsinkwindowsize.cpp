#include<bits/stdc++.h>
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
	unordered_map<int, int> m;
    //unordered_map<int, int> :: iterator i;
    vector<int> ans;
    for(int i=0; i<k-1;i++) m[arr[i]]++;
    int tmp=1, uq=0;
    for(int i=k-1; i<arr.size(); ){
        if(tmp==0){
            unordered_map<int, int> :: iterator it=m.find(arr[uq]);
            it->second--;
            if(it->second==0) m.erase(arr[uq]);
            uq++;
            tmp=1;
        }
        else{
            if(m.size()<k) m[arr[i]]++;
            ans.push_back(m.size());
            tmp=0;
            i++;
        }
    }
    return ans;
}
