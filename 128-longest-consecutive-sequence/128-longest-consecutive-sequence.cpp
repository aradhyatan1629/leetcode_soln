class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s;
        vector<int> v;
        int cnt=1,mx=INT_MIN;
        if(nums.size()==0)
        {
            return 0;
        }
        for(auto x:nums)
        {
            s.insert(x);
        }
        for(auto x:s)
        {
            v.push_back(x);
        }
        for(int i=0;i<v.size()-1;i++)
        {
            if(v[i+1]-v[i]==1)
            {
                cnt++;
            }
            else
            {
                mx=max(mx,cnt);
                cnt=1;
            }
        }
        mx=max(mx,cnt);
        return mx;
    }
};

// 0,0,1,2,3,4,5,6,7,8


// 0,1,1,2






