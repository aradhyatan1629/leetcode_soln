class Solution {
public:
    bool strongPasswordCheckerII(string p) {
        unordered_set<char> s = {'!','@','#','%','$','^','&','*','(',')','-','+'};
        if(p.size()<8)
        {
            return false;
        }
        int low=0,up=0,digit=0,sc=0;
        int flag=1;
        for(int i=0;i<p.size();i++)
        {
            if(p[i]>=65 and p[i]<=90)
            {
                up++;
            }
            if(p[i]>=97 and p[i]<=122)
            {
                low++;
            }
            if(p[i]>=48 and p[i]<=57)
            {
                digit++;
            }
            if(s.find(p[i])!=s.end())
            {
                sc++;
            }
            if(i<p.size()-1 and p[i]==p[i+1])
            {
                flag=-1;
            }
        }
        if(low<1 or up<1 or digit<1 or sc<1)
        {
            return false;
        }
        if(flag==-1)
        {
            return false;
        }
        return true;
    }
};