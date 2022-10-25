class Solution {
public:
    bool isSubsequence(string s, string t) {
        int j=0;
        int cnt=0;
        for(int i=0;i<t.size();i++)
        {
            if(t[i]==s[j])
            {
                cnt++;
                j++;
            }
        }
        if(cnt==s.size())
        {
            return true;
        }
        return false;
    }
};