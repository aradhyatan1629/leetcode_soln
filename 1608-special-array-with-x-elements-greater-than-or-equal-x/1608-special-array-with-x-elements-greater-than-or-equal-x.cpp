class Solution {
public:
    int specialArray(vector<int>& nums) {
        int n = nums.size();
        int x=1;
        for(;x<=n;x++)
        {
            int cnt=0;
            for(int i=0;i<nums.size();i++)
            {
                if(nums[i]>=x)
                {
                    cnt++;
                }
            }
            if(cnt==x)
            {
                return x;
            }
        }
        return -1;
    }
};