class Solution {
public:
    set<vector<int>> s;
    void solve(int ind,int n,vector<int> &nums,vector<int> &v)
    {
        if(ind>=n)
        {
            s.insert(v);
            return;
        }
        v.push_back(nums[ind]);
        solve(ind+1,n,nums,v);
        v.pop_back();
        solve(ind+1,n,nums,v);
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int> v;
        solve(0,n,nums,v);
        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};

/*
tc - nlogn + (2^n)*(klogk)
k is the average lenght of each subset
*/


