class Solution {
public:
    int minimumBuckets(string hamsters) {
        int n = hamsters.size();
        if(n==1 and hamsters[0]=='H')
            return -1;
        if(n==1 and hamsters[0]=='.')
            return 0;
        if(hamsters[0]=='H' and hamsters[1]=='H')
            return -1;
        else if(hamsters[n-1]=='H' and hamsters[n-2]=='H')
            return -1;
        
        for(int i=1;i<n-1;i++)
        {
            if(hamsters[i]=='H' and hamsters[i-1]=='H' and hamsters[i+1]=='H')
                return -1;
        }
        
        
        int cnt=0;
        unordered_map<int,int> m;
        if(hamsters[1]=='.' and hamsters[0]=='H')
            m[1]=1;
        
        for(int i=0;i<n;i++)
        {
            if(hamsters[i]=='.' and m[i]!=1)
            {
                if(i-1>=0 and i+1<n and (hamsters[i-1]=='H' and hamsters[i+1]=='H'))
                {
                    if(i-2>=0 and m[i-2]==1 and i+2<n and hamsters[i+2]=='.')
                        continue;
                    else
                        m[i]=1;
                }
                else if(hamsters[i]=='.' and (i+1<n and hamsters[i+1]=='H'))
                {
                    if(i+2<n and hamsters[i+2]=='.')
                        continue;
                    else
                        m[i]=1;
                }
                else if(i-1>=0 and (hamsters[i-1]=='H'))
                {
                    if(i-2>=0 and m[i-2]!=1)
                        m[i]=1;
                }
            }
        }
        for(auto x:m)
            if(x.second==1)
                cnt++;
        return cnt;
    }
};








































