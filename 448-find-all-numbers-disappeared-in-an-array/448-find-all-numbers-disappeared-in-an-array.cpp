class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> s;
        int n=nums.size();
        vector<int> ans;
        for(auto x:nums)
        {
            s.insert(x);
        }
        for(int i=1;i<=n;++i)
        {
            if(s.find(i)==s.end())
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};