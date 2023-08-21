class Solution {
public:
    
    void f(int ind,vector<int> &subs,vector<int> &nums,vector<vector<int>> &ans,int n)
    {
        if(ind>=n)
        {
            ans.push_back(subs);
            return;
        }
        subs.push_back(nums[ind]); //adding the element in our subsequence array
        f(ind+1,subs,nums,ans,n);  //take 
        subs.pop_back();           //bringing the array to the state it was in
        f(ind+1,subs,nums,ans,n);  //not take
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subs;
        f(0,subs,nums,ans,nums.size());
        return ans;
    }
};