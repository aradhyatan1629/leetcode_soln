class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        //O(nlogn) O(1)
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<0 and k>0)
            {
                nums[i]*=-1;
                k--;
            }
            else if(nums[i]>=0)
            {
                break;
            }
        }
        if(k%2!=0)
        {
            sort(nums.begin(),nums.end());
            while(k--)
            {
                nums[0]*=-1;
            }
        }
        return accumulate(nums.begin(),nums.end(),0);
    }
};