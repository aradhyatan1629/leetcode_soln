class Solution {
public:
    vector<vector<int>> ans;
    void solve(int ind,int n,int cnt,int k,vector<int> &nums,vector<int> &v)
    {
        if(ind>=n or cnt>=k)
        {
            if(cnt==k)
                ans.push_back(v);
            return;
        }
        v.push_back(nums[ind]);
        solve(ind+1,n,v.size(),k,nums,v);
        v.pop_back();
        solve(ind+1,n,v.size(),k,nums,v);
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;
        for(int i=1;i<=n;i++)
            nums.push_back(i);
        
        vector<int> v;
        solve(0,n,0,k,nums,v);
        // for(auto x:ans)
        // {
        //     for(auto y:x)
        //         cout<<y<<" ";
        //     cout<<endl;
        // }
        return ans;
    }
};