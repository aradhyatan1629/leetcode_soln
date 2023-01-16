class Solution {
public:
    bool isWord(char c)
    {
        if(c>=65 and c<=90 or c>=97 and c<=122 or c>=48 and c<=57)
        {
            return true;
        }
        return false;
    }
    bool isPalindrome(string s) {
        int n=s.size(),i=0,j=n-1;
        while(i<j)
        {
            if(isWord(s[i])==false)
            {
                while(i<n and isWord(s[i])==false)
                {
                    i++;
                }
            }
            if(isWord(s[j])==false)
            {
                while(j>=0 and isWord(s[j])==false)
                {
                    j--;
                }
            }
            if((i<n and j<n) and tolower(s[i])!=tolower(s[j]))
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};