class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k=p.size();
        int i=0,j=0,n=s.size();
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        vector<int> ans;
        for(auto x:p)
        {
            m1[x]++;
        }
        while(j<n)
        {
            m2[s[j]]++;
            int flag=1;
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                if(m1==m2)
                {
                    ans.push_back(i);
                }
                m2[s[i]]--;
                if(m2[s[i]]==0)
                {
                    m2.erase(s[i]);
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};