class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n,0);
        pre[0] = nums[0];
        int leftsum=0;
        int rightsum=0;
        
        for(int i=1;i<n;++i)
        {
            pre[i] = pre[i-1]+nums[i];
        }
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
                leftsum=0;
                rightsum = pre[n-1] - nums[0];
            }
            if(i==n-1)
            {
                rightsum=0;
                leftsum = pre[n-1] - nums[n-1];
            }
            else if(i>0 and i<n)
            {
                leftsum = pre[i] - nums[i];
                rightsum = pre[n-1] - pre[i];
            }
            if(leftsum==rightsum)
            {
                return i;
            }
        }
        return -1;
    }
};



// 2 5 4 12 16