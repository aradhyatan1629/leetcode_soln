class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]>=65 and s[i]<=90 or s[i]>=97 and s[i]<=122)
            {
                t+=s[i];
            }
            else if(s[i]>=48 and s[i]<=57)
            {
                t+=s[i];
            }
        }
        transform(t.begin(),t.end(),t.begin(),::tolower);
        string r=t;
        reverse(t.begin(),t.end());
        cout<<r<<endl;
        if(r==t)
        {
            return true;
        }
        return false;
    }
};