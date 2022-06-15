void fun(int i, int sum, vector<int> &a, vector<int> &ans){
    if(i==a.size()){
        ans.push_back(sum);
        return;
    }
    fun(i+1, sum+a[i], a, ans);
    fun(i+1, sum, a, ans);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int> ans;
    fun(0, 0, num, ans);
    sort(ans.begin(), ans.end());
    return ans;
}