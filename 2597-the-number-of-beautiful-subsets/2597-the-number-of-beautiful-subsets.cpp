class Solution {
public:
    bool check(vector<int> &v,int k)
    {
        int n = v.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(abs(v[i]-v[j])==k)
                    return false;
            }
        }
        return true;
    }
    
    void solve(int ind,vector<int> &v,vector<int> &nums,int k,int &ans)
    {
        if(ind<0)
        {
            if(v.size()>0 && check(v,k))
                ans++;
            return;
        }
        v.push_back(nums[ind]);
        solve(ind-1,v,nums,k,ans);
        v.pop_back();
        solve(ind-1,v,nums,k,ans);
    }
    
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        vector<int> v;
        solve(n-1,v,nums,k,ans);
        return ans;
    }
};