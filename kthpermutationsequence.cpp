string kthPermutation(int n, int k) {
    // Write your code here.
    string ans="";
        int fact=1; 
        vector<int> no;
        for(int i=1; i<n; i++){
            fact*=i;
            no.push_back(i);
        }
        no.push_back(n);
        k=k-1;
        while(true){
            ans=ans+to_string(no[k/fact]);
            no.erase(no.begin()+k/fact);
            if(no.size()==0) break;
            k=k%fact;
            fact/=no.size();
        }
        return ans;
}
