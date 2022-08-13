class Solution {
public:
    int countGoodSubstrings(string s) {
        int i=0,j=0,n=s.size();
        int flag=1;
        string word;
        int cnt=0;
        if(s.size()<3)
        {
            return 0;
        }
        while(j<n)
        {
            word+=s[j];
            if(j-i+1<3)
            {
                j++;
            }
            else if(j-i+1 == 3)
            {
                if((word[0]!=word[1]) and (word[1]!=word[2]) and (word[0]!=word[2]))
                {
                    cnt++;
                }
                    word.erase(word.begin());
                    i++;
                    j++;
            }
        }
        return cnt;
    }
};