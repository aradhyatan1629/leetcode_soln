class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int mx=INT_MIN;
        int index=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>mx)
            {
                mx=nums[i];
                index=i;
            }
        }
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]*2>mx && i!=index)
            {
                return -1;
            }
        }
        return index;
    }
};