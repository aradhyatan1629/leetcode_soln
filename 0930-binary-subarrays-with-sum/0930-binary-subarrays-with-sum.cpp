class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int sum=0,cnt=0;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            if(sum==goal)
            {
                cnt++;
            }
            if(m[sum-goal]>0)
            {
                cnt+=m[sum-goal];
            }
            m[sum]++;
        }
        return cnt;
    }
};