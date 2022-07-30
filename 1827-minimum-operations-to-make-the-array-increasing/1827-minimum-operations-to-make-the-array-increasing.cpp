class Solution {
public:
    int minOperations(vector<int>& nums) {
        int op=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            int mx = 0;
            if(nums[i]>=nums[i+1])
            {
                mx = max(nums[i]+1,nums[i+1]);
                op+=mx-nums[i+1];
                nums[i+1] = nums[i]+1;
            }
        }
        return op;
    }
};