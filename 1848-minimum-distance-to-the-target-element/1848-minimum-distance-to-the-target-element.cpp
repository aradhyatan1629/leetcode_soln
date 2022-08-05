class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int mn = INT_MAX;
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                res = abs(i-start);
                if(res<mn)
                {
                    mn=res;
                }
            }
        }
        return mn;
    }
};