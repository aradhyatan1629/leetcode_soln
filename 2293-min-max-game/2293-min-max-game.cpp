class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while(nums.size()!=1)
        {
            vector<int> newnums(nums.size()/2,0);
            for(int i=0;i<nums.size()/2;i+=2)
            {
                newnums[i] = min(nums[2*i],nums[2*i+1]);
            }
            for(int i=1;i<nums.size()/2;i+=2)
            {
                newnums[i] = max(nums[2*i],nums[2*i+1]);
            }
            nums=newnums;
        }
        return nums[0];
    }
};