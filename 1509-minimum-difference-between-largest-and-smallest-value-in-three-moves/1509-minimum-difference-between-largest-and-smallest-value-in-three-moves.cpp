class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4)
        {
            return 0;
        }
        int mn = INT_MAX;
        sort(nums.begin(),nums.end());
        
        int x = nums[3],y = nums[n-1];
        mn = min(mn,y-x);
        
        x=nums[0],y=nums[n-1-3];
        mn = min(mn,y-x);
        
        x=nums[1],y=nums[n-1-2];
        mn = min(mn,y-x);
        
        x=nums[2],y=nums[n-2];
        mn = min(mn,y-x);
        
        return mn;
    }
};