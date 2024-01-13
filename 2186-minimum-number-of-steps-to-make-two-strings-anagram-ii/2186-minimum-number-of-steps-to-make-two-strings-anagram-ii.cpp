class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> m1,m2;
        for(auto x:s)
            m1[x]++;
        for(auto x:t)
            m2[x]++;
        int ans=0;
        for(char i='a';i<='z';i++)
        {
            if(m1[i]!=m2[i])
                ans+=abs(m1[i]-m2[i]);
        }
        return ans;
    }
};