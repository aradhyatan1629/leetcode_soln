class Solution {
public:
    bool checkZeroOnes(string s) {
        int l1=0,l0=0;
        int mx1=0,mx0=0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                l1++;
                mx1=max(mx1,l1);
            }
            else
            {
                l1=0;
            }
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='0')
            {
                l0++;
                mx0=max(mx0,l0);
            }
            else
            {
                l0=0;
            }
        }
        if(mx1>mx0)
        {
            return true;
        }
        return false;
    }
};