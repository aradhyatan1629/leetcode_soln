class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i=0,j=0;
        while(i<nums.size() and nums[i]%2==0)
        {
            i++;
        }
        while(i<nums.size() and j<nums.size())
        {
            if(nums[i]%2==0 and nums[j]%2==1)
            {
                swap(nums[i],nums[j]);
                i++,j++;
            }
            else if(nums[i]%2!=0)
            {
                i++;
            }
            else if(nums[j]%2!=1)
            {
                j++;
            }
        }
        return nums;
    }
};


/*

[0,1]
[1,0]
[0,1]

[2,4,3,8,7]


*/




