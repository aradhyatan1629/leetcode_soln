class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int cnt0 = count(nums.begin(),nums.end(),0);
        vector<int> ans;
        if(cnt0>1)
        {
            ans.resize(nums.size(),0);
            return ans;
        }
        int prod=1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)continue;
            prod*=nums[i];
        }
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)ans.push_back(prod);
            else if(cnt0==1)ans.push_back(0);
            else ans.push_back(prod/nums[i]);
        }
        return ans;
    }
};