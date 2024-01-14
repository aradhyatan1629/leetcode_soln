class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> v(nums.size(),0);
        int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            int idx = (i+k)%n;
            v[idx]=nums[i];
        }
        nums = v;
    }
};


// (rotated index) = (index + k)%nums.size()