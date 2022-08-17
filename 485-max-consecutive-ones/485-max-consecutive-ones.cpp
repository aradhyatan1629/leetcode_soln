class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int mx=INT_MIN;
        int x=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==1)
            {
                x++;
            }
            else
            {
                mx=max(mx,x);
                x=0;
            }
        }
        mx=max(mx,x);
        return mx;
    }
};