class Solution {
public:
    string modifyString(string s) {
        string temp = "abcdefghijklmnopqrstuvwxyz";
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='?' and i==0)
            {
                for(int j=0;j<temp.size();j++)
                {
                    if(temp[j]!=s[i+1])
                    {
                        s[i]=temp[j];
                        break;
                    }
                }
            }
            if(s[i]=='?' and i==s.size()-1)
            {
                for(int j=0;j<temp.size();j++)
                {
                    if(temp[j]!=s[i-1])
                    {
                        s[i]=temp[j];
                        break;
                    }
                }
            }
            if(s[i]=='?' and (i>0 and i<s.size()-1))
            {
                for(int j=0;j<temp.size();j++)
                {
                    if(temp[j]!=s[i-1] and temp[j]!=s[i+1])
                    {
                        s[i]=temp[j];
                        break;
                    }
                }
            }
        }
        return s;
    }
};