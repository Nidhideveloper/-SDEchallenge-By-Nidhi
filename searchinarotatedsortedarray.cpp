int search(int* nums, int n, int target) {
    // Write your code here.
    int l=0, r=n-1;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]<nums[r]){
                //right side sorted
                if(target>nums[mid] && target<=nums[r]){
                    l=mid+1;
                }
                else r=mid-1;
            }
            else{
                //left side sorted
                if(target>=nums[l] && target<nums[mid]){
                    r=mid-1;
                }
                else l=mid+1;
            }
        }
        return -1;
}