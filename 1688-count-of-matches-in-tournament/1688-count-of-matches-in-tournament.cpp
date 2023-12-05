class Solution {
public:
    int numberOfMatches(int n) {
        int adv = 0;
        int cnt=0;
        
        while(n!=1)
        {
            if(n%2 == 0)
            {
                cnt += n/2;
                n = n/2;
            }
            else
            {
                cnt += (n-1)/2;
                n = ceil((double)n/2.0);
            }
        }
        return cnt;
    }
};





/*



*/