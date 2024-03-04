class Solution {
public:
    int solve(int n,vector<int> &nums)
    {
        int prev=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++)
        {
            int pick = nums[i];
            if(i>1)
                pick+=prev2;
            int notPick = 0 + prev;
            int curr = max(pick,notPick);
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        return solve(n,nums);
    }
};