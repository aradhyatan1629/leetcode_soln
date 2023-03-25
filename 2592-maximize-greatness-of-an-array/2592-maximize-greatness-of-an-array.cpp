class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int i=0,j=0,cnt=0;
        while(j<nums.size())
        {
            if(nums[i]>=nums[j])
            {
                j++;
            }
            else if(nums[i]<nums[j])
            {
                cnt++;
                i++;
                j++;
            }
        }
        return cnt;
    }
};

// 1 1 1 2 3 3 5