class Solution {
public:
    bool isVowel(char ch)
    {
        if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u' or ch=='A'
           or ch=='E' or ch=='I' or ch=='O' or ch=='U')
            return true;
        return false;
    }
    
    bool halvesAreAlike(string s) {
        int cnt=0;
        for(int i=0;i<s.size()/2;i++)
            if(isVowel(s[i]))
                cnt++;
        for(int i=s.size()/2;i<s.size();i++)
            if(isVowel(s[i]))
                cnt--;
        if(cnt==0)
            return true;
        return false;
    }
};