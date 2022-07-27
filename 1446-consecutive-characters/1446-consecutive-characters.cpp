class Solution {
public:
    int maxPower(string s) {
        int i=0,j=0,length=1;
        int ans=INT_MIN;
        for(i=0;i<s.size();i++)
        {
            length=1;
            for(j=i+1;j<s.size();j++)
            {
                if(s[i]==s[j])
                {
                    length++;
                }
                else
                {
                    break;
                }
            }
            if(length>ans)
            {
                ans=length;
            }
        }
        return ans;
    }
};