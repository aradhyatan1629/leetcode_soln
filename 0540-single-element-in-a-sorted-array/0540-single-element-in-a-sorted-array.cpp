class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        while(low<high)
        {
            int mid = (low + high)/2;
            if(mid%2==0 and nums[mid]==nums[mid+1] or mid%2==1 and nums[mid]==nums[mid-1])
            {
                low = mid+1;
            }
            else
            {
                high=mid;
            }
        }
        return nums[low];
    }
};



// 1 1 2 3 3 4 4 8 8 
