class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        left[0] = nums[0];
        for(int i=1;i<n;i++)
        {
            left[i] = left[i-1]+nums[i];
        }
        right[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i] = right[i+1] + nums[i];
        }
        for(int i=0;i<n;++i)
        {
            if(left[i]==right[i])
            {
                return i;
            }
        }
        return -1;
    }
};