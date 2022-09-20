class Solution {
public:
    bool isvowel(char c)
    {
        if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u')
        {
            return true;
        }
        return false;
    }
    int maxVowels(string s, int k) {
        int mx=INT_MIN;
        int n=s.size();
        int i=0,j=0;
        string word;
        int cnt=0;
        while(j<n)
        {
            word+=s[j];
            if(isvowel(s[j]))
            {
                cnt++;
            }
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                mx=max(mx,cnt);
                if(isvowel(word[0]))
                {
                    cnt--;
                }
                word.erase(word.begin());
                i++;
                j++;
            }
        }
        return mx;
    }
};