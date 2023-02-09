class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        vector<int> v;
        int cnt=0;
        for(auto x:nums)
        {
            if(x%2==0)
            {
                v.push_back(0);
            }
            else
            {
                v.push_back(1);
            }
        }
        vector<int> pre(v.size(),0);
        pre[0]=v[0];
        for(int i=1;i<v.size();i++)
        {
            pre[i]=pre[i-1]+v[i];
        }
        for(int i=0;i<pre.size();i++)
        {
            m[pre[i]]++;
            if(pre[i]==k)
            {
                cnt++;
            }
            if(m[pre[i]-k]>0)
            {
                cnt+=m[pre[i]-k];
            }
        }
        return cnt;
    }
};

// 0 0 0 1 0 0 1 0 0 0
// 0 0 0 1 1 1 2 2 2 2