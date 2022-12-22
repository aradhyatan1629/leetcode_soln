class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string temp1,temp2;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='#' and temp1.size()!=0)
            {
                temp1.erase(temp1.end()-1);
            }
            else if(s[i]=='#' and temp1.size()==0)
            {
                continue;
            }
            else
            {
                temp1+=s[i];
            }
        }
        for(int i=0;i<t.size();i++)
        {
            if(t[i]=='#' and temp2.size()!=0)
            {
                temp2.erase(temp2.end()-1);
            }
            else if(t[i]=='#' and temp2.size()==0)
            {
                continue;
            }
            else
            {
                temp2+=t[i];
            }
        }
        if(temp1==temp2)
        {
            return true;
        }
        return false;
    }
};