class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>> v;
        unordered_map<int,int> m;
        for(auto x:nums)
        {
            m[x]++;
        }
        for(auto x:m)
        {
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end());
        vector<int> ans;
        for(auto it=v.end()-1;it>=v.begin();it--)
        {
            if(k==0)
            {
                break;
            }
            ans.push_back(it->second);
            k--;
        }
        return ans;
    }
};