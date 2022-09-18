class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0,high=n-1;
        int midindex=-1;
        //Finding the index of minimum element
        while(low<=high)
        {
            if(nums[low]<=nums[high])
            {
                midindex=low;
                break;
            }
            int mid=low+(high-low)/2;
            int prev=(mid+n-1)%n;
            int next=(mid+1)%n;
            if(nums[mid]<=nums[prev] and nums[mid]<=nums[next])
            {
                midindex=mid;
                break;
            }
            else if(nums[mid]>=nums[low])
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        low=0,high=midindex-1;
        //Searching in first sorted array
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        //Searching in second sorted array
        low=midindex,high=n-1;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid]<target)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return -1;
    }
};