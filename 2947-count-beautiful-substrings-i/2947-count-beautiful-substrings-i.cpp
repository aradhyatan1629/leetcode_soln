class Solution {
public:
    int isVowel(char c)
    {
        if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u')
            return true;
        return false;
    }
    
    int beautifulSubstrings(string s, int k) {
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            int v=0,c=0;
            for(int j=i;j<s.size();j++)
            {
                if(isVowel(s[j]))
                    v++;
                else
                    c++;
                if(v==c and (v*c)%k == 0)
                    ans++;
            }
        }
        return ans;
    }
};