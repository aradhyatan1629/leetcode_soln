class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        {
            return false;
        }
        long long int rev=0,rem=0;
        long long int num=x;
        while(num!=0)
        {
            rem=num%10;
            rev=(rev*10)+rem;
            num=num/10;
        }
        if(rev==x)
        {
            return true;
        }
        return false;
    }
};