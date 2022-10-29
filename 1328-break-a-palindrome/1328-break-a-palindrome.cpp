class Solution {
public:
    string breakPalindrome(string palindrome) {
        if(palindrome.size()==1)
        {
            return "";
        }
//         change the first non 'a' character to 'a'
        for(int i=0;i<palindrome.size()/2;i++)
        {
            if(palindrome[i]!='a')
            {
                palindrome[i]='a';
                return palindrome;
            }
        }
//         for cases like "aa" "aaa"
        int n=palindrome.size();
        palindrome[n-1]='b';
        return palindrome;
    }
};