class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int r=0;
        for(int i=0;i<=nums.size();i++)
        {
            r^=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            r^=nums[i];
        }
        return r;
    }
};

