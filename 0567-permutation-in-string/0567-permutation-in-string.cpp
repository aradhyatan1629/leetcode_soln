class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> v(26,0);
        vector<int> t(26,0);
        for(int i=0;i<s1.size();i++)
        {
            v[s1[i]-'a']++;
        }
        t=v;
        for(int i=0;i<s2.size();i++)
        {
            if(v[s2[i]-'a']>0)
            {
                for(int j=i;j<s2.size();j++)
                {
                    if(v[s2[j]-'a']>0)
                    {
                        v[s2[j]-'a']--;
                    }
                    else
                    {
                        if(count(v.begin(),v.end(),0)==26)
                        {
                            return true;
                        }
                        v=t;
                        break;
                    }
                }
                if(count(v.begin(),v.end(),0)==26)
                {
                    return true;
                }
            }
            v=t;
        }
        
        return false;
    }
};