class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cnt=1;
        int mx=1;
        for(int i=0;i<nums.size()-1;i++)
        {
            if(nums[i]<nums[i+1])
            {
                cnt++;
                mx=max(cnt,mx);
            }
            else
            {
                cnt=1;
            }
        }
        return mx;
    }
};