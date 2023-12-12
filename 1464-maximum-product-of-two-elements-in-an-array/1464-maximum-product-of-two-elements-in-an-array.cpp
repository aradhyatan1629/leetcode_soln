class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int indMx=-1,indMx1=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(indMx==-1)
            {
                indMx = i;
            }
            else if(nums[i]>nums[indMx])
            {
                indMx1 = indMx;
                indMx = i;
            }
            else if(indMx1==-1 or nums[i]>nums[indMx1])
            {
                indMx1 = i;
            }
        }
        return (nums[indMx1]-1) * (nums[indMx]-1);
    }
};