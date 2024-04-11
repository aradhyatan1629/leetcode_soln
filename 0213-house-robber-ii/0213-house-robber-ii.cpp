class Solution {
public:
    int solve(int ind,vector<int> &dp,vector<int> &nums)
    {
        if(ind==0)
            return nums[0];
        if(ind<0)
            return 0;
        if(dp[ind]!=-1)
            return dp[ind];
        int take = nums[ind] + solve(ind-2,dp,nums);
        int notTake = 0 + solve(ind-1,dp,nums);
        dp[ind] = max(take,notTake);
        return dp[ind];
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return nums[0];
        vector<int> v1,v2;
        for(int i=0;i<n;i++)
        {
            if(i!=n-1)
                v1.push_back(nums[i]);
            if(i!=0)
                v2.push_back(nums[i]);
        }
        vector<int> dp(n+1,-1);
        int s1 = solve(v1.size()-1,dp,v1);
        for(auto &x:dp)x=-1;
        int s2 = solve(v2.size()-1,dp,v2);
        return max(s1,s2);
    }
};