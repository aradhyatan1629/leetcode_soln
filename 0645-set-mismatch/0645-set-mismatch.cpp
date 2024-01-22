class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]++;
            if(m[nums[i]]==2)
                ans.push_back(nums[i]);
        }
        for(int i=1;i<=n;i++)
            if(m[i]==0)
                ans.push_back(i);
        return ans;
    }
};