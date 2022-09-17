class Solution {
public:
    int findMin(vector<int>& nums) {
        //O(n) solution
        int mn=INT_MAX;
        int index=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]<mn)
            {
                mn=nums[i];
            }
        }
        return mn;
    }
};