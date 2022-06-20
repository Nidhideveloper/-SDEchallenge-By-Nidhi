void solve(int i, vector<int> &a, vector<int> &tmp, vector<vector<int>> &ans){
    if(i==a.size()){
        ans.push_back(tmp);
        return;
        
    }
    //pick
    tmp.push_back(a[i]);
    solve(i+1, a, tmp, ans);
    tmp.pop_back();
    
    //not pick
    solve(i+1, a, tmp, ans);
}
vector<vector<int>> pwset(vector<int>v)
{
    //Write your code here
    vector<vector<int>> ans;
    vector<int> tmp;
    solve(0, v, tmp, ans);
    return ans;
}