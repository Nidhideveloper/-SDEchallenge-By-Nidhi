int uniqueElement(vector<int> nums, int n)
{
	// Write your code here
    int l=0, r=nums.size()-2;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==nums[mid^1]) l=mid+1;
            else r=mid-1;
        }
        return nums[l];
}