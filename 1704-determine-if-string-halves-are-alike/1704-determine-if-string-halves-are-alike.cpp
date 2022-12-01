class Solution {
public:
    bool vowel(char x)
    {
        if(x=='a' or x=='e' or x=='i' or x=='o' or x=='u')
        {
            return true;
        }
        else if(x=='A' or x=='E' or x=='I' or x=='O' or x=='U')
        {
            return true;
        }
        return false;
    }
    bool halvesAreAlike(string s) {
        int cnt=0;
        for(int i=0;i<s.size()/2;i++)
        {
            if(vowel(s[i]))
            {
                cnt++;
            }
        }
        for(int i=s.size()/2;i<s.size();i++)
        {
            if(vowel(s[i]))
            {
                cnt--;
            }
        }
        if(cnt==0)
        {
            return true;
        }
        return false;
    }
};