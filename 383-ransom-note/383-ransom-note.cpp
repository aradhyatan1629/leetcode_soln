class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> m;
        for(auto x:magazine)
        {
            m[x]++;
        }
        for(auto x:ransomNote)
        {
            if(m[x]==0)
            {
                return false;
            }
            else
            {
                m[x]-=1;
            }
        }
        return true;
    }
};