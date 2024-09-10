class Solution {
private:
    vector<vector<int>> ans;
public:
    bool check(vector<int> &v,unordered_set<int> &s){
        for(int i=0;i<v.size();i++){
            if(s.find(v[i])!=s.end())
                return false;
        }
        return true;
    }
    
    void solve(int ind,vector<int> &nums,vector<int> &v,int k,int target,unordered_set<int> &s,int sz){
        
        if(ind >= nums.size()){
            if(target == 0 && v.size() == sz){
                ans.push_back(v);
                for(auto x:v)s.insert(x);
            }
            return;
        }
        
        if(nums[ind] <= target && k>0 ){
            v.push_back(nums[ind]);
            solve(ind+1,nums,v,k-1,target-nums[ind],s,sz);
            v.pop_back();
        }
        solve(ind+1,nums,v,k,target,s,sz);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        vector<int> v;
        unordered_set<int> s;
        solve(0,nums,v,k,n,s,k);
        return ans;
    }
};

// 1,2,3,4,5,6,7,8,9