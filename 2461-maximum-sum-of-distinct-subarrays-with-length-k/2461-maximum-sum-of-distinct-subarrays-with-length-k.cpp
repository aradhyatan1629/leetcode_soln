class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int i=0,j=0,n=nums.size();
        long long ans = 0;
        long long sum = 0;
        
        while(j<n){
            m[nums[j]]++;
            sum += nums[j];
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                if(m.size() == k){
                    ans = max(ans,sum);
                }
                m[nums[i]]--;
                if(m[nums[i]] == 0)m.erase(nums[i]);
                sum -= nums[i];
                i++,j++;
            }
        }
        return ans;
    }
};