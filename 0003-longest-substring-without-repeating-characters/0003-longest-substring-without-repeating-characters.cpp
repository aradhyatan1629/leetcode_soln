class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int mx=INT_MIN;
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(m.find(s[i])==m.end())
            {
                m[s[i]]=i;
                cnt++;
            }
            else
            {
                i=m[s[i]];
                mx=max(mx,cnt);
                cnt=0;
                m.clear();
            }
        }
        mx=max(mx,cnt);
        return mx;
    }
};
// pwacduava
// ecbadfbayrtsabc