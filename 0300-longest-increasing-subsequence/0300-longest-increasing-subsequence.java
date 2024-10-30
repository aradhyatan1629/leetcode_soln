class Solution {
    public int solve(int ind,int prevInd,int[] nums,int[][] dp){
        if(ind >= nums.length)
            return 0;
        
        if(dp[ind][prevInd + 1] != -1)
            return dp[ind][prevInd + 1];
        
        int notTake = 0 + solve(ind+1,prevInd,nums,dp);
        
        int take = 0;
        if(prevInd == -1 || nums[ind] > nums[prevInd]){
            take = 1 + solve(ind+1,ind,nums,dp);
        }
        
         return dp[ind][prevInd+1] = Math.max(notTake, take);
    }
    
    public int lengthOfLIS(int[] nums) {
        int[][] dp = new int[nums.length][nums.length+1];
        
        for(int i=0;i<nums.length;i++){
             for(int j = 0; j <= nums.length; j++) {
                dp[i][j] = -1;
            }
        }
        
        return solve(0, -1, nums, dp);
    }
}