class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for(int i=0;i<nums.size();i++)
        {
            sort(nums[i].begin(),nums[i].end());
        }
        int j=0;
        int score=0;
        while(j<nums[0].size())
        {
            int mx = INT_MIN;
            for(int i=0;i<nums.size();i++)
            {
                mx = max(mx,nums[i][j]);
            }
            score+=mx;
            j++;
        }
        return score;
    }
};