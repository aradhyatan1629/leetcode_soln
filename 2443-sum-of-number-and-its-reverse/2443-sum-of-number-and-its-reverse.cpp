class Solution {
public:
    int reverse(int n)
    {
        int r = 0;
        while(n)
        {
            r = r*10 + n%10;
            n/=10;
        }
        return r;
    }
    
    bool sumOfNumberAndReverse(int num) {
        for(int i=0;i<=num;i++)
        {
            if(i+reverse(i) == num)
                return true;
        }
        return false;
    }
};