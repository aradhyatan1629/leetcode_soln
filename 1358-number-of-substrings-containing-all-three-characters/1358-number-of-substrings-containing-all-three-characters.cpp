class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> m;
        int cnt=0;
        int i=0,j=0,n=s.size();
        while(j<n)
        {
            m[s[j]]++;
            if(m.size()<3)
            {
                j++;
            }
            else if(m.size()==3)
            {
                while(m.size()==3)
                {
                    cnt+=(n-j);
                    m[s[i]]--;
                    if(m[s[i]]==0)
                    {
                        m.erase(s[i]);
                    }
                    i++;
                }
                j++;
            }
        }
        return cnt;
    }
};

// aabcbabc