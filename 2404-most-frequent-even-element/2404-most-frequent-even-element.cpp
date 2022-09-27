class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto x:nums)
        {
            if(x%2==0)
            {
                m[x]++;
            }
        }
        int mx=INT_MIN;
        int mn=INT_MAX;
        for(auto x:m)
        {
            mx=max(mx,x.second);
        }
        for(auto x:m)
        {
            if(x.second==mx)
            {
                mn=min(mn,x.first);
            }
        }
        if(mn==INT_MAX)
        {
            return -1;
        }
        return mn;
    }
};