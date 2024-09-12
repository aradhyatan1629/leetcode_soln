class Solution {
public:
    bool check(vector<int> &v,int k){
        int n = v.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(abs(v[i]-v[j]) == k)
                    return false;
            }
        }
        return true;
    }
    
    void solve(int ind,vector<int> &nums,vector<int> &v,int k,int &ans){
        if(ind >= nums.size()){
            if(v.size()>0 && check(v,k))
                ans++;
            return;
        }
        v.push_back(nums[ind]);
        solve(ind+1,nums,v,k,ans);
        v.pop_back();
        solve(ind+1,nums,v,k,ans);
    }
        
    int beautifulSubsets(vector<int>& nums, int k) {
        int ans = 0;
        vector<int> v;
        solve(0,nums,v,k,ans);
        return ans;
    }
};