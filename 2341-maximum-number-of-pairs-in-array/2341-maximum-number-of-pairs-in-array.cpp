class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        vector<int> v;
        int n = nums.size();
        int i=0;
        for(auto x:nums)
        {
            m[x]++;
        }
        int pr=0;
        for(auto x:m)
        {
            pr+=x.second/2;
        }
        int t = n - pr*2;
        v.push_back(pr);
        v.push_back(t);
        return v;
    }
};