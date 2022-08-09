class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> s;
        int cnt=0;
        for(auto x:nums)
        {
            s.insert(x);
        }
        for(auto x:s)
        {
            if(x!=0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};