class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int cnt=1;
        long mx=INT_MIN;
        for(int i=0;i<nums.size()-1;i++)
        {
            cnt=1;
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[j-1]<nums[j])
                {
                    cnt++;
                    continue;
                }
                else
                {
                    break;
                }
            }
            if(cnt>mx)
            {
                mx=cnt;
            }
        }
        if(mx==INT_MIN)
        {
            return 1;
        }
        return mx;
    }
};