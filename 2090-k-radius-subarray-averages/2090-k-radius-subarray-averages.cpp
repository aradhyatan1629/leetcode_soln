class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size(),sz=0;
        vector<long long> pre(n,0);
        vector<int> ans;
        pre[0] = nums[0];
        int j=0;
        for(int i=1;i<nums.size();i++)
        {
            pre[i] =  pre[i-1] + nums[i];
        }
        for(int i=0;i<pre.size();i++)
        {
            if(i-k>=0 and i+k<pre.size())
            {
                if(i-k==0)
                {
                    sz = i+k+1;
                    ans.push_back(pre[i+k]/sz);
                }
                else
                {
                    ans.push_back((pre[i+k]-pre[j])/sz);
                    j++;
                }
            }
            else
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};


/*
7 11 14 23 24 32 37 39 45
*/