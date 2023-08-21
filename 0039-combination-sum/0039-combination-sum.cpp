class Solution {
public:
    
    void findCombination(int ind,vector<int> &subs,vector<int> &nums,vector<vector<int>> &ans,int target)
    {
        if(ind>=nums.size())
        {
            if(target==0)
            {
                ans.push_back(subs);
            }
            return;
        }
        if(nums[ind]<=target)
        {
            subs.push_back(nums[ind]);
            findCombination(ind,subs,nums,ans,target-nums[ind]);
            subs.pop_back();
        }
        findCombination(ind+1,subs,nums,ans,target);
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> subs;
        findCombination(0,subs,candidates,ans,target);
        return ans;
    }
};