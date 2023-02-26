class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0)
        {
            return nums;
        }
        int n=nums.size();
        vector<long long int> pre(n,0);
        vector<int> ans;
        pre[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            pre[i]=pre[i-1] + nums[i];
        }
        for(int i=0;i<pre.size();i++)
        {
            if(i-k<0 or i+k>=n)
            {
                ans.push_back(-1);
            }
            else
            {
                if(i-k>0)
                {
                    long long int s = pre[i+k] - pre[i-k-1];
                    long long int t = (s/((k*2)+1));
                    ans.push_back(t);
                }
                else
                {
                    long long int s = pre[i+k];
                    long long int t = (s/((k*2)+1));
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};

// 0 1 2 3 4 5 6 7 8
// 7 4 3 9 1 8 5 2 6

// 7 11 14 23 24 32 37 39 45
// 0  1  2  3  4  5  6  7  8