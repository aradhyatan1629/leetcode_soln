class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n,0);
        unordered_map<int,int> m;
        pre[0]=nums[0];
        int cnt=0;
        for(int i=1;i<nums.size();i++)
        {
            pre[i]=pre[i-1]+nums[i];
        }
        for(int i=0;i<pre.size();i++)
        {
            if(pre[i]==k)
            {
                cnt++;
            }
            if(m[pre[i]-k]>0)
            {
                cnt+=m[pre[i]-k];
            }
            m[pre[i]]++;
        }
        return cnt;
    }
};
