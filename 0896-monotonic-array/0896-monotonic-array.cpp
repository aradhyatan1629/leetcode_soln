class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size()==1)
        {
            return true;
        }
        bool inc = false;
        bool dec = false;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                inc=true;
            }
            else if(nums[i]<nums[i-1])
            {
                dec=true;
            }
        }
        if(inc and dec)
        {
            return false;
        }
        return true;
    }
};