class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind,int target,int n,vector<int> &v,vector<int>& candidates)
    {
        if(ind>=n)
        {
            if(target == 0)
                ans.push_back(v);
            return;
        }
        if(candidates[ind]<=target)
        {
            v.push_back(candidates[ind]);
            solve(ind,target-candidates[ind],n,v,candidates);
            v.pop_back();
        }
        solve(ind+1,target,n,v,candidates);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> v;
        solve(0,target,candidates.size(),v,candidates);
        return ans;
    }
};