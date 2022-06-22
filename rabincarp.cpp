vector<int> stringMatch(string &str, string &pat) {
    // Write your code here
    vector<int> ans;
    for(int i=0; i<=str.size()-pat.size(); i++){
        int k=0, cnt=0;
        for(int j=i; j<i+pat.size(); j++){
            if(str[j]==pat[k]) cnt++;
            k++;
        }
        if(cnt==pat.size()) ans.push_back(i);
    }
    return ans;
}
