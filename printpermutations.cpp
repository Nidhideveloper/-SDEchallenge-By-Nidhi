void solve(string &s, vector<string> &ans, string &ds, int freq[]){
    if(ds.size()==s.size())
        {
            ans.push_back(ds);
            return;
        }
        for(int i=0;i<s.size();i++)
        {
            if(!freq[i])
            {
                ds.push_back(s[i]);
                freq[i]=1;
                solve(s,ans,ds,freq);
                freq[i]=0;
                ds.pop_back();
            }
        }
}

vector<string> findPermutations(string &s) {
    // Write your code here.
    vector<string> ans;
    string str="";
    int freq[s.size()];
    for(int i=0; i<s.size(); i++){
        freq[i]=0;
    }
    solve(s, ans, str, freq);
    return ans;
}