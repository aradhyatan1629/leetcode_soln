class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //O(n) solution - 
        if(nums.size()==1)
        {
            return 0;
        }
        if(nums.size()>=2 and nums[0]>nums[1])
        {
            return 0;
        }
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i-1] and nums[i]>nums[i+1])
            {
                return i;
            }
        }
        return nums.size()-1;
    }
};