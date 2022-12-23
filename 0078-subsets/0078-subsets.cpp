class Solution {
public:
    vector<vector<int>> ans;
    void f(int ind,vector<int> &subs,vector<int> &nums,int n)
    {
        if(ind>=n)
        {
            ans.push_back(subs);
            return;
        }
        else
        {
            subs.push_back(nums[ind]);
            f(ind+1,subs,nums,n);
            subs.pop_back();
            f(ind+1,subs,nums,n);
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subs;
        int n=nums.size();
        f(0,subs,nums,n);
        return ans;
    }
};