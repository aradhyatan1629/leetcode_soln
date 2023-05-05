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
        int cnt=0,ans=0;
        int i=0,j=0,n=s.size();
        while(j<n)
        {
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
                ans = max(cnt,ans);
                if(isvowel(s[i]))
                {
                    cnt--;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};