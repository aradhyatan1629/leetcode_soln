class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,pair<int,int>> m;
        int mx=INT_MIN;
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            if(m[s[i]].first==0)
            {
                m[s[i]].second=i;
                m[s[i]].first=1;
                cnt++;
            }
            else
            {
                mx=max(mx,cnt);
                cnt=0;
                i=m[s[i]].second;
                m.clear();
            }
        }
        mx=max(mx,cnt);
        return mx;
    }
};
// pwacduava
// ecbadfbayrtsabc