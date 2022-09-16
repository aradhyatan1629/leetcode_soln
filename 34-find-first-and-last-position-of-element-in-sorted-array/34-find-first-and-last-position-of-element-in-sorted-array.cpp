class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //Binary Search O(logn) soln-
        int n=nums.size();
        vector<int> ans{-1,-1};
        int l=0,h=n-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(nums[mid]==target)
            {
                ans[0]=mid;
                h=mid-1;
            }
            else if(nums[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        l=0,h=n-1;
        while(l<=h)
        {
            int mid=(l+h)/2;
            if(nums[mid]==target)
            {
                ans[1]=mid;
                l=mid+1;
            }
            else if(nums[mid]<target)
            {
                l=mid+1;
            }
            else
            {
                h=mid-1;
            }
        }
        return ans;
    }
};