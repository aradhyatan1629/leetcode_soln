class Solution {
public:
    int reverse(int x) {
        long long rev = 0;
        while(x!=0)
        {
            long long t = x%10;
            rev = rev*10 + t;
            x/=10;
        }
        if(rev<INT_MIN or rev>INT_MAX)
        {
            return 0;
        }
        return rev;
    }
};