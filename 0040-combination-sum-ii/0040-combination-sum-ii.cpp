class Solution {
public:
    
    vector<vector<int>> ans;
    void solve(int ind,int n,int target,vector<int> &candidates,vector<int> &v)
    {
        if(target==0)
        {
            ans.push_back(v);
            return;
        }
        if(target<0 or ind>=n)
        {
            return;
        }
        v.push_back(candidates[ind]);
        solve(ind+1,n,target-candidates[ind],candidates,v);
        v.pop_back();
        while(ind<n-1 and candidates[ind]==candidates[ind+1])
            ind++;
        solve(ind+1,n,target,candidates,v);
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n=candidates.size();
        vector<int> v;
        solve(0,n,target,candidates,v);
        return ans;
    }
};

/*

tc - (2^n)*k where k is the avg length of each combination
that sums to target, it is due to ans.push_back(v);
to not take duplicates first sort the array then - 
while(ind<n and candidates[ind]==candidates[ind+1])
            ind++;
*/



