class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mx=0;
        int i=0,j=nums.size()-1;
        while(i<j)
        {
            mx = max(mx,nums[i]+nums[j]);
            i++,j--;
        }
        return mx;
    }
};


/*

2 3 3 5
2 3 4 5 5 5

*/