class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
       //O(n) solution-
        int n=nums.size();
        int i=0,j=n-1;
        if(n==0)
        {
            return {-1,-1};
        }
        while(nums[i]!=target)
        {
            i++;
            if(i>n-1)
            {
                return {-1,-1};
            }
        }
        while(nums[j]!=target)
        {
            j--;
        }
        return {i,j};
    }
};