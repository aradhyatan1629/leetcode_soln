class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int mx=INT_MIN;
        if(s=="")
        {
            return 0;
        }
        for(int i=0;i<s.size();i++)
        {
            int cnt=0;
            for(int j=i;j<s.size();j++)
            {
                if(m[s[j]]==0)
                {
                    m[s[j]]++;
                    cnt++;
                }
                else
                {
                    mx=max(mx,cnt);
                    m.clear();
                    break;
                }
            }
            mx=max(mx,cnt);
        }
        return mx;
    }
};