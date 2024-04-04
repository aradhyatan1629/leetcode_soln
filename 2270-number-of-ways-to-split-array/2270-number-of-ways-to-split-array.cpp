class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long sum = 0;
        for(int i=0;i<nums.size();i++)
            sum += nums[i];
        int cnt = 0;
        long long leftSum = 0,rightSum = sum;
        for(int i=0;i<nums.size()-1;i++)
        {
            leftSum += nums[i];
            rightSum = sum - leftSum;
            if(leftSum >= rightSum)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
