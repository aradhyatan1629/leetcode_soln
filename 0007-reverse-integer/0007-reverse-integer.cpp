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
        if(rev<pow(-2,31) or rev>pow(2,31))
        {
            return 0;
        }
        return rev;
    }
};