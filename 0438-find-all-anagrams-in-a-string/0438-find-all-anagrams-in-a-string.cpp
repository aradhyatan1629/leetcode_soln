class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char,int> m,m1;
        vector<int> ans;
        for(auto x:p)
        {
            m1[x]++;
        }
        int i=0,j=0,n=s.size(),k=p.size();
        while(j<n)
        {
            m[s[j]]++;
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                if(m==m1)
                {
                    ans.push_back(i);
                }
                m[s[i]]--;
                if(m[s[i]]==0)
                {
                    m.erase(s[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};