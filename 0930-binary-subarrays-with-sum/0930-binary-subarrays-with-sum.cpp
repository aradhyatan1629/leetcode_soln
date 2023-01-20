class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size(),cnt=0;
        vector<int> pre(n,0);
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        unordered_map<int,int> m;
        for(int i=0;i<pre.size();i++)
        {
            if(pre[i]==goal)
            {
                cnt++;
            }
            if(m[pre[i]-goal]>0)
            {
                cnt+=m[pre[i]-goal];
            }
            m[pre[i]]++;
        }
        return cnt;
    }
};
// 1 1 2 2 3