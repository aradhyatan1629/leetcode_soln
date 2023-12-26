class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int diff=INT_MAX,ans=0;
        
        for(int i=0;i<n;i++)
        {
            if(i>0 and nums[i]==nums[i-1])
                continue;
            int j = i+1;
            int k = n-1;
            while(j<k)
            {
                int sum = nums[i]+nums[j]+nums[k];
                int t = target - sum;
                if(abs(t) < abs(diff))
                {
                    ans = sum;
                    diff = t;
                }
                if(sum < target)
                {
                    j++;
                }
                else if(sum > target)
                {
                    k--;
                }
                else
                {
                    return target;
                }
            }
        }
        return ans;
    }
};