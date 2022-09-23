class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> t;
        vector<int> perm(n,0);
        vector<int> arr(n,0);
        int cnt=0;
        for(int i=0;i<n;++i)
        {
            perm[i]=i;
        }
        t=perm;
        
        while(true)
        {
            for(int i=0;i<n;++i)
            {
                if(i%2==0)
                {
                    arr[i]=perm[i/2];
                }
                if(i%2==1)
                {
                    arr[i] = perm[n / 2 + (i - 1) / 2];
                }
            }
            cnt++;
            perm=arr;
            if(t==perm)
            {
                break;
            }
        }
        return cnt;
    }
};