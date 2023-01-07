class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int cnt=0;
        vector<long long> v;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                cnt++;
            }
            else
            {
                v.push_back(cnt);
                cnt=0;
            }
        }
        if(cnt!=0)
        {
            v.push_back(cnt);
        }
        long long int ans=0;
        for(auto x:v)
        {
            if(x%2==0)
            {
                long long int t = x/2;
                ans+=(x*t)+t;
            }
            else
            {
                ans+=(x*((x/2)+1));
            }
        }
        return ans;
    }
};

// 0 0 0 0 0 0
/*
1 - 1
2 - 3
3 - 6
4 - 10
5 - 15
6 - 21
*/

/*
1*1
3*2
5*3
7*4

*/