class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] ans = new int[2];
        int low=0,high=nums.length-1;
        int ind = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                ind = mid;
                high = mid-1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        ans[0] = ind;
        low=0;
        high=nums.length-1;
        ind=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                ind = mid;
                low = mid+1;
            }
            else if(nums[mid] < target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        ans[1]=ind;
        return ans;
    }
}