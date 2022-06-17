#include <bits/stdc++.h>
void func(int idx, string &s, unordered_map<string,int> &m, string& cur, string& word, vector<string>&ans){
    if(idx==s.size()-1){
        word.push_back(s[idx]);
        cur.push_back(s[idx]);
        if(m[word])ans.push_back(cur);
        word.pop_back();
        cur.pop_back();
        return;
    }
    word.push_back(s[idx]);
    cur.push_back(s[idx]);
    if(m[word]){
        cur.push_back(' ');
        string w="";
        func(idx+1,s,m,cur,w,ans);
        cur.pop_back();
    }
    func(idx+1,s,m,cur,word,ans);
    word.pop_back();
    cur.pop_back();
}
vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    vector<string>ans;
    string cur="",word="";
    unordered_map<string,int>m;
    for(string str:dictionary){
        m[str]=1;
    }
    func(0,s,m,cur,word,ans);
    return ans;
}