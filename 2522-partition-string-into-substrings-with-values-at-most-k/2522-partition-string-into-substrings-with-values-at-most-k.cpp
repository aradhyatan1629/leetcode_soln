class Solution {
public:
    int minimumPartition(string s, int k) {     
        long long int n=0;
        
        for(int i=0;i<s.size();i++)
        {
            if(s[i]-'0' > k)
                return -1;
        }
        
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            n = n*10 + (s[i]-'0');
            if(n > k)
            {
                n = s[i]-'0';
                ans++;
            }
        }
        return ans+1;
    }
};