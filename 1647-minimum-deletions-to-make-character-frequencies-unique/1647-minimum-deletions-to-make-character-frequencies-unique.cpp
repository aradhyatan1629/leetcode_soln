class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> m;
        unordered_map<int,int> m1;
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
        }
        for(auto x:m)
        {
            int t = x.second;
            if(m1.find(t)!=m1.end())
            {
                while(m1.find(t)!=m1.end())
                {
                    cnt++;
                    t--;
                }
            }
            if(t!=0)
            {
                m1[t]=1;
            }
        }
        return cnt;
    }
};