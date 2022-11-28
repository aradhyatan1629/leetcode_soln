class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int mx=INT_MIN,len=1;
        if(nums.size()==1)
        {
            return 1;
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            len=1;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j]>nums[j-1])
                {
                    len++;
                }
                else
                {
                    break;
                }
            }
            mx=max(mx,len);
        }
        mx=max(mx,len);
        return mx;
    }
};