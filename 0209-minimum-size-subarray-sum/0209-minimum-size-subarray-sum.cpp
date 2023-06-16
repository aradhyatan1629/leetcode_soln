class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,j=0,n=nums.size();
        long long sum = 0;
        int ans = INT_MAX;
        while(j<n)
        {
            sum+=nums[j];
            if(sum>=target)
            {
                ans = min(ans,j-i+1);
                while(i<n and sum>=target)
                {
                    sum-=nums[i];
                    i++;
                    if(sum>=target)
                    {
                        ans = min(ans,j-i+1);
                    }
                }
            }
            j++;
        }
        if(ans==INT_MAX)
        {
            return 0;
        }
        return ans;
    }
};