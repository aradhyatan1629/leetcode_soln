class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> s(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            string x=to_string(nums[i]);
            reverse(x.begin(),x.end());
            s.insert(stoi(x));
        }
        return s.size();
    }
};