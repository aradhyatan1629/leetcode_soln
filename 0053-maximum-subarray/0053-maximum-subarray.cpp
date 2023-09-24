class Solution {
public:
    
    //kadane's algorithm O(n)
    int maxSubArray(vector<int>& nums) {
        int mx = INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            if(sum>mx)
            {
                mx=sum;
            }
            if(sum<0) // if we carry negative sum forward, the total sum will always reduce
            {
                sum=0;
            }
        }
        return mx;
    }
};

/*The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. A subarray with a sum less than 0 will always reduce our answer and so this type of subarray cannot be a part of the subarray with maximum sum.*/