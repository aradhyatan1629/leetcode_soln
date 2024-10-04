class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;  // {prefSum,cnt}
        int sum = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            if(sum == k)
                ans++;
            if(m.find(sum-k) != m.end())
                ans += m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};

/*

nums = [1,2,3,-3,1,1,1]
k = 3

*/