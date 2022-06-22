bool areAnagram(string &s, string &t){
    // Write your code here.
    if(s.length() != t.length()) return false;
        vector<int> v(26);
        for(int i=0; i<s.length(); i++){
            v[s[i]-'a']++;
            v[t[i]-'a']--;
            
        }
        for(auto &i:v){
            if(i!=0) return false;
        }
        
        return true;
}