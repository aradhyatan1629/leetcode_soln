class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int len=1,mx=INT_MIN;
        if(nums.size()==1)
        {
            return 1;
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                len++;
            }
            else
            {
                mx=max(mx,len);
                len=1;
            }
        }
        mx=max(mx,len);
        return mx;
    }
};