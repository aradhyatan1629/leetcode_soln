class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int i=0,j=0;
        int cnt=0;
        for(int k=2;k<=s.size();k++)
        {
            string word;
            i=0,j=0;
            while(j<n)
            {
                word+=s[j];
                if(j-i+1<k)
                {
                    j++;
                }
                else if(j-i+1==k)
                {
                    string temp=word;
                    reverse(temp.begin(),temp.end());
                    if(temp==word)
                    {
                        cnt++;
                    }
                    word.erase(word.begin());
                    i++;
                    j++;
                }
            }
        }
        return cnt+s.size();
    }
};