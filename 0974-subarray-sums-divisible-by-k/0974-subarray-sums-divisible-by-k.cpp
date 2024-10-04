class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> m; // {remainder,index}
        int sum = 0;
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int rem = (sum%k+k)%k;
            if(rem == 0)
                ans++;
            if(m.find(rem) != m.end())
                ans += m[rem];
            m[rem]++;
        }
        return ans;
    }
};