class Solution {
public:
    bool canConstruct(string r, string m) {
        unordered_map<char,int> mp;
        for(auto x:m)
        {
            mp[x]++;
        }
        for(int i=0;i<r.size();i++)
        {
            if(mp[r[i]]==0)
            {
                return false;
            }
            else
            {
                mp[r[i]]-=1;
            }
        }
        return true;
    }
};