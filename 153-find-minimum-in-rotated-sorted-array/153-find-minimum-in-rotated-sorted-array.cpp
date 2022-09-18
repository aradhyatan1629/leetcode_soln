class Solution {
public:
    int findMin(vector<int>& nums) {
        int l=0,h=nums.size()-1;
        int n=nums.size();
        while(l<=h)
        {
            if(nums[l]<=nums[h])
            {
                return nums[l];
            }
            int mid=l+(h-l)/2;
            int prev=(mid+n-1)%n;
            int next=(mid+1)%n;
            if(nums[mid]<=nums[prev] and nums[mid]<=nums[next])
            {
                return nums[mid];
            }
            else if(nums[mid]>=nums[l])
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return 0;
    }
};