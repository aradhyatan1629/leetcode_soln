class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int i=nums.size();
        while(k--)
        {
            i--;
        }
        return nums[i];
    }
};

// 6 5 4 3 2 1 - 5
// 6 5 5 4 3 3 2 2 1

// 1 2 3 4 5 6
// 1 2 2 3 4 5 5 6