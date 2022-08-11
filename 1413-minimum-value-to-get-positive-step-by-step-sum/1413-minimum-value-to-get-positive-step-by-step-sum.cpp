class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n,0);
        pre[0] = nums[0];
        for(int i=1;i<n;++i)
        {
            pre[i] = pre[i-1] + nums[i];
        }
        int mn = INT_MAX;
        for(auto x:pre)
        {
            mn=min(x,mn);
        }
        if(mn<0)
        {
            return abs(mn)+1;
        }
        return 1;
    }
};
    
/*
-3 -1 -4 0 2
1 3
*/