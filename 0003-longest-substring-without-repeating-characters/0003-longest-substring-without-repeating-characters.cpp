class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int mx = 0;
        int i=0,j=0,n=s.size();
        while(j<n)
        {
            if(m[s[j]]==0)
            {
                m[s[j]] = 1;
                j++;
            }
            else
            {
                mx = max(mx,j-i);
                while(m[s[j]]!=0)
                    m[s[i]]--,i++;
                m[s[j]]=1;
                j++;
            }
        }
        mx = max(mx,j-i);
        return mx;
    }
};