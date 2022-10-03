class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> ans;
        int cnt=nums.size()/3;
        for(auto x:nums)
        {
            m[x]++;
        }
        for(auto x:nums)
        {
            if(m[x]>cnt)
            {
                ans.push_back(x);
                m.erase(x);
            }
        }
        return ans;
    }
};