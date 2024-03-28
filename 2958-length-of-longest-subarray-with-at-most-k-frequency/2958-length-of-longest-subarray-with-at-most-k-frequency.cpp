class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size();
        unordered_map<int,int> m;
        int mx = 0;
        while(j<n)
        {
            m[nums[j]]++;
            while(m[nums[j]]>k)
                m[nums[i]]--,i++;
            mx = max(mx,j-i+1);
            j++;
        }
        return mx;
    }
};