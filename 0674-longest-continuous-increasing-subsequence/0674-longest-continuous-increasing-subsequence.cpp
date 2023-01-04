class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int mx=1;
        if(nums.size()==1)
        {
            return 1;
        }
        for(int i=0;i<nums.size()-1;i++)
        {
            int j=i;
            int len=1;
            while(j<nums.size()-1 and nums[j]<nums[j+1])
            {
                j++;
                len++;
            }
            mx=max(mx,len);
        }
        return mx;
    }
};