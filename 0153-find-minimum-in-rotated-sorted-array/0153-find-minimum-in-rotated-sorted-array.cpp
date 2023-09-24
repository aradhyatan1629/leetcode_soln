class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0,high=nums.size()-1;
        int mn = INT_MAX;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            
            if(nums[low]<=nums[mid])            //if left half is sorted
            {
                mn = min(mn,nums[low]);
                low = mid+1;
            }
            else                              //if right half is sorted
            {
                mn = min(mn,nums[mid]);
                high=mid-1;
            }
        }
        return mn;
    }
};


//Find the sorted half, and in that sorted half the first element is the min element