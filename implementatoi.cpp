int atoi(string s) {
    // Write your code here.
    int sign =1;
    int i=0, ans=0;
    if(s[i]=='-'){
        sign=-1;
        i++;
    }
    for(; i<s.size(); i++){
        if(s[i]-'0'>=0 && s[i]-'0'<=9) ans=ans*10+s[i]-'0';
    }
    return ans*sign;
}