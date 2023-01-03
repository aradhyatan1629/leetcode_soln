class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> m;
        int n=nums.size();
        int t=n/3;
        for(auto x:nums)
        {
            m[x]++;
        }
        for(auto x:nums)
        {
            if(m[x]!=0)
            {
                int cnt=m[x];
                if(cnt>t)
                {
                    ans.push_back(x);
                }
                m.erase(x);
            }
        }
        return ans;
    }
};