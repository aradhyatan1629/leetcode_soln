class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        unordered_map<int,bool> m;
        for(auto x:nums)
        {
            m[x]=true;
        }
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            if(m[nums[i]-diff] && m[nums[i]+diff])
            {
                cnt++;
            }
        }
        return cnt;
    }
};