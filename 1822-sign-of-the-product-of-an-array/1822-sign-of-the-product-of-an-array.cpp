class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n=0;
        for(auto x:nums)
        {
            if(x==0)
            {
                return 0;
            }
            else if(x<0)
            {
                n++;
            }
        }
        if(n%2==0)
        {
            return 1;
        }
        return -1;
    }
};