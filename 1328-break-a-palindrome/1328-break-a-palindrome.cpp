class Solution {
public:
    string breakPalindrome(string palindrome) {
        string s=palindrome;
        int j=0;
        int cnt=0;
        while(j<palindrome.size())
        {
            string s=palindrome;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]=='a')
                {
                    cnt++;
                    continue;
                }
                s[i]='a';
                string x=s;
                reverse(x.begin(),x.end());
                if(s==x)
                {
                    s=palindrome;
                    break;
                }
                else if(s!=x)
                {
                    return s;
                }
            }
            j++;
        }
        if(cnt>1)
        {
            for(int i=palindrome.size();i>=0;i--)
            {
                if(palindrome[i]=='a')
                {
                    palindrome[i]='b';
                    return palindrome;
                }
            }
        }
        return "";
    }
};