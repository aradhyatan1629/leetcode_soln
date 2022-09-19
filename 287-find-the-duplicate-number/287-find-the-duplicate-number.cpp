class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //Solution using extra space
        unordered_map<int,int> m;
        for(auto x:nums)
        {
            m[x]++;
        }
        for(auto x:m)
        {
            if(x.second!=1)
            {
                return x.first;
            }
        }
        return 0;
    }
};


