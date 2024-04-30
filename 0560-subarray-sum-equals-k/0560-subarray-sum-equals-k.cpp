class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int sum = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            if(sum == k)
                cnt++;
            if(m[sum-k]>0)
                cnt+= m[sum-k];
            m[sum]++;
        }
        return cnt;
    }
};