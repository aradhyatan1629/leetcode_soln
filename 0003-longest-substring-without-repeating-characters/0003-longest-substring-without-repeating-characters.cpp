class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int i=0,j=0,n=s.size();
        int mx=0;
        while(j<n)
        {
            if(m[s[j]]==0)
            {
                m[s[j]]++;
                j++;
            }
            else
            {
                mx = max(mx,j-i);
                while(i<n and m[s[j]]==1)
                {
                    m[s[i]]--;
                    i++;
                }
            }
        }
        mx = max(mx,j-i);
        return mx;
    }
};