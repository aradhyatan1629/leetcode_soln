class Solution {
public:
    string shortestCompletingWord(string l, vector<string>& w) {
        transform(l.begin(),l.end(),l.begin(),::tolower);
        string t;
        for(int i=0;i<l.size();i++)
        {
            if(l[i]>=97 and l[i]<=122)
            {
                t+=l[i];
            }
        }
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;
        for(auto x:t)
        {
            m1[x]++;
        }
        int sz=INT_MAX;
        int ans=0;
        for(int i=0;i<w.size();i++)
        {
            int flag=1;
            for(int j=0;j<w[i].size();j++)
            {
                m2[w[i][j]]++;
            }
            for(auto x:t)
            {
                if(m2[x]<m1[x])
                {
                    flag=-1;
                    break;
                }
            }
            if(flag==1 and w[i].size()<sz)
            {
                ans=i;
                sz=w[i].size();
            }
            m2.clear();
        }
        return w[ans];
    }
};