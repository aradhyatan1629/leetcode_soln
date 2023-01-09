class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0,j=0,n=s.size();
        unordered_map<char,int> m;
        int mx=0;
        while(j<n and i<n)
        {
            m[s[j]]++;
            if(m[s[j]]>1)
            {
                mx=max(mx,j-i);
                while(j<n and m[s[j]]!=1)
                {
                    m[s[i]]--;
                    if(m[s[i]]==0)
                    {
                        m.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
            else
            {
                j++;
            }
        }
        mx=max(mx,j-i);
        return mx;
    }
};