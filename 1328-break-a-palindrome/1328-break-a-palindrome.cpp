class Solution {
public:
    string breakPalindrome(string palindrome) {
        string s=palindrome;
        vector<char> v={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
        
        int j=0,k=0;
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
                s[i]=v[k];
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
            k++;
            if(k==v.size())
            {
                k=0;
            }
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