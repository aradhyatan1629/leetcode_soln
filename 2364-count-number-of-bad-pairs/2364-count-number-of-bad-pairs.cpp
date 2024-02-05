class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]-i]++;
        }
        long long cnt = 0;int n=nums.size();
        for(int i=0;i<nums.size();i++)
        {
            if(m[nums[i]-i]>1)
            {
                cnt += (n-i-m[nums[i]-i]);
            }
            else
            {
                cnt += (n-i-1);
            }
            m[nums[i]-i]--;
        }
        return cnt;
    }
};