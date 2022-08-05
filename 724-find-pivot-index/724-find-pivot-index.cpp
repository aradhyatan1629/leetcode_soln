class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> pre(nums.size(),0);
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        int n = pre.size();
        int i=0;
        for(i=0;i<n;i++)
        {
            int leftsum = 0;
            int rightsum = 0;
            if(i==0)
            {
                leftsum=0;
                rightsum = pre[n-1]-nums[0];
            }
            if(i==n-1)
            {
                leftsum=pre[n-1]-nums[n-1];
                rightsum=0;
            }
            else if(i>0 and i<n)
            {
                leftsum = pre[i]-nums[i];
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

