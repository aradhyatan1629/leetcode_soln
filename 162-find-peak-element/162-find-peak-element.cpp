class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        //O(n) solution
        int n=nums.size();
        int ans=0;
        if(nums.size()==1)
        {
            return 0;
        }
        if(nums[0]>nums[1])
        {
            return 0;
        }
        if(nums[n-1]>nums[n-2])
        {
            return n-1;
        }
        for(int i=1;i<nums.size()-1;i++)
        {
            if(nums[i]>nums[i-1] and nums[i]>nums[i+1])
            {
                ans=i;
                break;
            }
        }
        return ans;
    }
};