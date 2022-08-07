class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n=s.size();
        int i=0;
        int j=n-1;
        while(i<j)
        {
            if((s[i]>=65 and s[i]<=90) or(s[i]>=97 and s[i]<=122))
            {
                if((s[j]>=65 and s[j]<=90) or(s[j]>=97 and s[j]<=122))
                {
                    swap(s[i],s[j]);
                    i++;
                    j--;
                }
                else
                {
                    j--;
                }
            }
            else
            {
                i++;
            }
        }
        return s;
    }
};