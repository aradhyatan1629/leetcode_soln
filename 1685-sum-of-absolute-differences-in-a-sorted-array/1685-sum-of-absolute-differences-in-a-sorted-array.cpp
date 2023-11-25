class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int leftSum=0,rightSum=0,n=nums.size();
        for(int i=0;i<nums.size();i++)
            rightSum+=nums[i];
        
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            int t = (nums[i]*i-leftSum) + (rightSum-(nums[i]*(n-i)));
            ans.push_back(t);
            leftSum+=nums[i];
            rightSum-=nums[i];
        }
        return ans;
    }
};









