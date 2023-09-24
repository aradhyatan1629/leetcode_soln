class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int i=0,j=0,n=s.size();
        int mx = 0;
        
        while(j<n)
        {
            m[s[j]]++;
            if(m[s[j]]==1)
            {
                mx = max(mx,j-i+1);
                j++;
            }
            else
            {
                while(i<n and m[s[j]]!=1)
                {
                    m[s[i]]--;
                    i++;
                }
                j++;
            }
        }
        return mx;
    }
};