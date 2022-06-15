int removeDuplicates(vector<int> &nums, int n) {
	// Write your code here.
    if(n==0) return 0;
        int cnt=0;
        for(int i=1; i<nums.size(); i++){
            if(nums[i]!=nums[i-1]) {cnt++;
                                    nums[cnt]=nums[i];}
            
        }
        return cnt+1;
}