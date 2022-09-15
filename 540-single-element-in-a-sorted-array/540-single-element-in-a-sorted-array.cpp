class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int r=0;
        for(int i=0;i<nums.size();i++)
        {
            r^=nums[i];
        }
        return r;
    }
};