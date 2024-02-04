class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        for(auto x:t)
            m[x]++;
        int ans=INT_MAX;
        int i=0,j=0,start=0;
        int count = m.size();
        
        while(j<s.size())
        {
            m[s[j]]--;
            if(m[s[j]]==0)
                count--;
            if(count==0)
            {
                while(count==0)
                {
                    if(ans>j-i+1)
                    {
                        ans = j-i+1;
                        start=i;
                    }
                    m[s[i]]++;
                    if(m[s[i]]>0)
                        count++;
                    i++;
                }
            }
            j++;
        }
        if(ans == INT_MAX)
            return "";
        return s.substr(start,ans);
    }
};