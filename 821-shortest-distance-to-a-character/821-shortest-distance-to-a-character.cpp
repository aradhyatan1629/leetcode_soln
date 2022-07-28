class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int d1=INT_MAX;
        int i=0,j=0,n=s.size();
        vector<int> ans;
        for(i=0;i<n;++i)
        {
            d1=INT_MAX;
            for(j=0;j<n;++j)
            {
                if(s[j]==c)
                {
                    if(abs(j-i)<d1)
                    {
                        d1=abs(j-i);
                    }
                }
            }
            ans.push_back(d1);
        }
        return ans;
    }
};