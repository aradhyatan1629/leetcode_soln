class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size(),median;
        
        if(n%2==0)
            median = (nums[n/2-1] + nums[n/2])/2;
        else
            median = nums[n/2];
        
        int op=0;
        for(int i=0;i<nums.size();i++)
        {
            op+=abs(median-nums[i]);
        }
        return op;
    }
};


