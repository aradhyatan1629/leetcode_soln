class Solution {
public:
    int fib(int n) {
        if(n<=1)
            return n;
        int prev1=0,prev=1,curr;
        for(int i=2;i<=n;i++)
        {
            curr = prev + prev1;
            prev1 = prev;
            prev = curr;
        }
        return prev;
    }
};