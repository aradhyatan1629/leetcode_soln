class Solution {
public:
    int mySqrt(int x) {
        long long low=1,high=x;
        while(low<=high)
        {
            long long mid = low + (high-low)/2;
            long long p = mid*mid;
            if(p == x)
            {
                return mid;
            }
            else if(p<x)
            {
                low = mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return high;
    }
};