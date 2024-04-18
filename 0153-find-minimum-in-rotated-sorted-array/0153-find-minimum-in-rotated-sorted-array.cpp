class Solution {
public:
    int findMin(vector<int>& nums) {
        int mn = INT_MAX;
        int low = 0,high=nums.size()-1;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(nums[low]<=nums[mid])
                mn = min(mn,nums[low]),low=mid+1;
            else if(nums[mid]<=nums[high])
                mn = min(mn,nums[mid]),high=mid-1;
        }
        return mn;
    }
};