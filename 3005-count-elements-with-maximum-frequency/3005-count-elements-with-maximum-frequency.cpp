class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> m;
        int mx=0;
        for(auto x:nums)
        {
            m[x]++;
            if(m[x]>mx)
                mx = m[x];
        }
        int ans=0;
        for(auto x:m)
        {
            if(x.second==mx)
                ans+=x.second;
        }
        return ans;
    }
};