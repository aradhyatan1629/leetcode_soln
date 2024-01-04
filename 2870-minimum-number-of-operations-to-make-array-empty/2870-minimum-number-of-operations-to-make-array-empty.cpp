class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto x:nums)
            m[x]++;
        int ans = 0;
        for(auto x:m)
        {
            if(x.second == 1)
                return -1;
            else if(x.second%3 == 0)
                ans += x.second/3;
            else if(x.second%3 == 1 or x.second%3 == 2)
                ans += x.second/3 + 1;
        }
        return ans;
    }
};


/*
12 - 9
14-10

*/

















