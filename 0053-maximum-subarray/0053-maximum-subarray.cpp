class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN,sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
            if(sum > mx)
            {
                mx = sum;
            }
            if(sum < 0)
            {
                sum = 0;
            }
        }
        return mx;
    }
};