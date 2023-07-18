class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0,high = nums.size()-1;
        
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] == target)
            {
                return mid;
            }
            else if(nums[low]<=nums[mid])                     //if left half if sorted
            {
                if(nums[low]<=target and target<=nums[mid])  //if target is in this range
                {
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
            else                                             //if right half is sorted
            {
                if(nums[mid]<=target and target<=nums[high]) //if target is in this range
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
        }
        return -1;
    }
};