class Solution {
public:
    int longestBeautifulSubstring(string word) {
        vector<char> v = {'a','e','i','o','u'};
        int k=0;
        int i=0,j=0,n=word.size();
        
        int mx=0;
        
        while(j<n and word[j]!='a')
            i++,j++;
            
        
        while(j<n)
        {
            if(word[j]==v[k])
            {
                j++;
            }
            else
            {
                k++;
                if(k==5)
                {
                    mx = max(mx,j-i);
                    k=0;
                    i=j;
                }
                else if(word[j]!=v[k])
                {
                    while(j<n and word[j]!='a')
                    {
                        j++;
                    }
                    i=j;
                    k=0;
                }
                else
                {
                    j++;
                }
            }
        }
        if(k==4)
        {
            mx = max(mx,j-i);
        }
        return mx;
    }
};