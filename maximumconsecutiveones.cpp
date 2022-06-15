int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int i=0;
   int j=0;
   int ans=0;
   int kdup=k;
   while(j<n && i<n){
       if(arr[j]==1){
           ans=max(j-i+1,ans);
           j++;
       }
       else if(arr[j]==0){
           if(k){
               k--;
               ans=max(j-i+1,ans);
               j++;
           }
           else{
               if(arr[i]==0){
                   if(k<kdup)
                       k++;
               }
               i++;
           }
       }
   }
   return ans;
}
