class Solution {
public:
    
    int rev(int n)
    {
        int r=0;
        while(n)
        {
            r = r*10 + n%10;
            n/=10;
        }
        return r;
    }
    
    int countNicePairs(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]-rev(nums[i])]++;
        }
        
        long long ans=0;
        int mod = 1e9+7;
        for(auto x:m)
        {
            if(x.second>1)
            {
                long long t = x.second-1;
                ans = (int)(((long long int)ans + ((t*(t+1))/2) ) % mod);
            }
        }
        
        return ans;
    }
};


/*

123


13 - 31 = -18
10 - 1 = 9
35 - 53 = -18
24 - 42 = -18
76 - 67 = 9


*/


